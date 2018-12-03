import os
import matplotlib
matplotlib.use('Agg')
from sklearn.metrics import roc_curve, roc_auc_score
from scipy.interpolate import InterpolatedUnivariateSpline
from pdb import set_trace
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import root_numpy
import ROOT
from ROOT import TCanvas, TGraph
from ROOT import gROOT
from math import sin
from array import array
listbranch = ['Jet_pt','Jet_DeepFlavourBDisc','Jet_hadronFlavour']


def draw_roc_mean(df, df2, label, color, draw_unc=False, ls='-', draw_auc=True):
    newx = np.logspace(-3, 0, 100)
    tprs = pd.DataFrame()
    scores = []
    tmp_fpr, tmp_tpr, _ = roc_curve(np.clip(df['isB']+df['isBB']+df['isLeptonicB_C']+df['isLeptonicB']+df['isGBB'],0,1), df2)
    scores.append(
        roc_auc_score(np.clip(df['isB']+df['isBB']+df['isLeptonicB_C']+df['isLeptonicB']+df['isGBB'],0,1), df2)
    )
    coords = pd.DataFrame()
    coords['fpr'] = tmp_fpr
    coords['tpr'] = tmp_tpr
    clean = coords.drop_duplicates(subset=['fpr'])
    spline = InterpolatedUnivariateSpline(clean.fpr, clean.tpr,k=1)
    tprs = spline(newx)
    scores = np.array(scores)
    auc = ' AUC: %.3f +/- %.3f' % (scores.mean(), scores.std()) if draw_auc else ''
        
    plt.plot(tprs, newx, label=label + auc, c=color, ls=ls)

def draw_roc(df, df2, label, color, draw_unc=False, ls='-', draw_auc=True, flavour = False):
    newx = np.logspace(-3, 0, 100)
    tprs = pd.DataFrame()
    scores = []
    if flavour:
        cs = ( (df['isC'] == 0) & (df['isCC'] == 0) & (df['isGCC'] == 0) )
    else:
        cs = ( (df['isUD'] == 0) & (df['isS'] == 0) & (df['isG'] == 0) )
    df = df[cs]
    df2 = df2[cs]
    tmp_fpr, tmp_tpr, _ = roc_curve(np.clip(df['isB']+df['isBB']+df['isLeptonicB_C']+df['isLeptonicB']+df['isGBB'],0,1), df2['prob_isBB']+df2['prob_isB'])
    scores.append(
        roc_auc_score(np.clip(df['isB']+df['isBB']+df['isLeptonicB_C']+df['isLeptonicB']+df['isGBB'],0,1), df2['prob_isB']+df2['prob_isBB'])
    )
    coords = pd.DataFrame()
    coords['fpr'] = tmp_fpr
    coords['tpr'] = tmp_tpr
    clean = coords.drop_duplicates(subset=['fpr'])
    spline = InterpolatedUnivariateSpline(clean.fpr, clean.tpr,k=1)
    tprs = spline(newx)
    scores = np.array(scores)
    auc = ' AUC: %.3f +/- %.3f' % (scores.mean(), scores.std()) if draw_auc else ''
        
    plt.plot(tprs, newx, label=label + auc, c=color, ls=ls)


def draw_roc_btag(df, label, color, draw_unc=False, ls='-', draw_auc=True, flavour = False):
    newx = np.logspace(-3, 0, 100)
    tprs = pd.DataFrame()
    scores = []
    if flavour:
        cs = ( (df['Jet_hadronFlavour'] != 4) & (df['Jet_pt'] > 30) )
    else:
        cs = ( (df['Jet_hadronFlavour'] != 0) & (df['Jet_pt'] > 30) )
    df = df[cs]
    blab = (df['Jet_hadronFlavour'] == 5)*1
    tmp_fpr, tmp_tpr, _ = roc_curve(blab, df['Jet_DeepFlavourBDisc'])
    scores.append(
        roc_auc_score(blab, df['Jet_DeepFlavourBDisc'])
    )
    coords = pd.DataFrame()
    coords['fpr'] = tmp_fpr
    coords['tpr'] = tmp_tpr
    clean = coords.drop_duplicates(subset=['fpr'])
    spline = InterpolatedUnivariateSpline(clean.fpr, clean.tpr,k=1)
    tprs = spline(newx)
    scores = np.array(scores)
    auc = ' AUC: %.3f +/- %.3f' % (scores.mean(), scores.std()) if draw_auc else ''
        
    plt.plot(tprs, newx, label=label + auc, c=color, ls=ls)

def spit_out_roc(df, label, color, draw_unc=False, ls='-', draw_auc=True, flavour = False):

    newx = np.logspace(-3, 0, 100)
    tprs = pd.DataFrame()
    scores = []
    if flavour:
        cs = ( (df['Jet_hadronFlavour'] != 4) & (df['Jet_DeepFlavourBDisc'] > 0) )
    else:
        cs = ( (df['Jet_hadronFlavour'] != 0)  & (df['Jet_DeepFlavourBDisc'] > 0) )
    df = df[cs]
    blab = (df['Jet_hadronFlavour'] == 5)*1
    tmp_fpr, tmp_tpr, _ = roc_curve(blab, df['Jet_DeepFlavourBDisc'])
    scores.append(
        roc_auc_score(blab, df['Jet_DeepFlavourBDisc'])
    )
    coords = pd.DataFrame()
    coords['fpr'] = tmp_fpr
    coords['tpr'] = tmp_tpr
    clean = coords.drop_duplicates(subset=['fpr'])
    spline = InterpolatedUnivariateSpline(clean.fpr, clean.tpr,k=1)
    tprs = spline(newx)
    scores = np.array(scores)
    auc = ' AUC: %.3f +/- %.3f' % (scores.mean(), scores.std()) if draw_auc else ''
    
    return tprs, newx


pred = []


rfile2 = ROOT.TChain("t2")
rfile2.Add('../UnpackedBtagAna.root')

truth = root_numpy.tree2array(rfile2, branches = listbranch)
print truth.shape

plt.figure(figsize=(18,10))

x1, y1 = spit_out_roc(truth, '', 'blue', draw_auc=False, flavour = True)
x2, y2 = spit_out_roc(truth, '', 'blue', draw_auc=False, flavour = False)

f = ROOT.TFile("OldMiniAOD.root", "recreate")
gr1 = TGraph( 100, x1, y1 )
gr1.SetName("roccurve_0")
gr2 = TGraph( 100, x2, y2 )
gr2.SetName("roccurve_1")
gr1.Write()
gr2.Write()
f.Write()

