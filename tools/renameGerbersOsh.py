# ========================================================================
# A simple python script used to rename gerber files generated from KiCad 
# for delivery to Oshpark.com. The script also creates a zip file 
# containing all the renamed gerber files. 
#
#   projName-B_Cu.gbr -> projName.GBL
#   etc.
#
# Syntax: renameGerbersOsh.py <dir-to-kicad-gerbers> <kicad-project-name>
#
# Example: 
#   Place script file in the same folder as the KiCad-generated gerbers
#   and run
#     > python renameGerbersOsh.py . projName
#   where projName is the KiCad project name.
#
# Author: osannolik@godtycklig.se 
# Date: 2015-05-30
# ========================================================================

#!/usr/bin/python
import sys
import os
import zipfile

def renameGerbers(dir, name):

  replacePairsKicad = ["F_Cu","B_Cu","F_Mask","B_Mask","F_SilkS","B_SilkS","Edge_Cuts","In1_Cu","In2_Cu"]
  replacePairsOsh   =   [".GTL",".GBL",".GTS",".GBS",".GTO",".GBO",".GKO",".G2L",".G3L"]
  replaceDrillKicad = ".drl"
  replaceDrillOsh   = ".XLN"

  zipFiles = []

  if os.path.exists(dir):
    print ">  Renaming gerber files (KiCad -> Oshpark) ..."
    for f in os.listdir(dir):
      # Gerbers
      if f.endswith(".gbr"):
        for K in replacePairsKicad:
          if f==name+"-"+K+".gbr":
            newName = name+replacePairsOsh[replacePairsKicad.index(K)]
            print ">  "+f+" -> "+newName
            os.rename(f,newName)
            zipFiles.append(newName)

      # Drill
      if f.endswith(replaceDrillKicad):
        if f==name+replaceDrillKicad:
          newName = name+replaceDrillOsh
          print ">  "+f+" -> "+newName
          os.rename(f,newName)
          zipFiles.append(newName)

  # Create zip file
  if zipFiles:
    zipName = name+".zip"
    print ">  Adding files to "+zipName
    zf = zipfile.ZipFile(zipName,"w")
    for f in zipFiles:
      zf.write(f,os.path.basename(f), zipfile.ZIP_DEFLATED)
    zf.close()

if len(sys.argv)!=3:
  print ">  Syntax: "+sys.argv[0]+" <dir-to-kicad-gerbers> <kicad-project-name>"
else:
  renameGerbers(sys.argv[1], sys.argv[2])
