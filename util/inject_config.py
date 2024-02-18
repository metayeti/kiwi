################################################################################
#
#  inject_config utility
#  (for kiwi)
#
#  ---
#
#  This utility injects data from dev/config.ini into src/res/ini_resources.h
#
#  !! WARNING !!
#  For safety, always run on a clean working tree, then diff and make sure
#  everything is in order before committing to branch!
#
#  ---
#
#  !! DEFINITELY !! do NOT run if you have no idea what you're doing.
#
################################################################################

import fileinput
import sys

# target source file
targetFile = '../src/res/ini_resources.h'

# input INI file
inputFile = '../dev/config.ini'

# target line-number
lineToUpdate = 28

# target string format
lineFormat = '\tconst char* const INI_CONFIG = "{inidata}";'

def readINIData():
    iniData = '';
    with open(inputFile, 'r') as file:
        iniData = file.read() \
            .replace('\\', '\\\\') \
            .replace('"', '\\"') \
            .replace('\n', '\\n')
    return iniData

def outputTargetFileWithSubstituted(iniData):
    for i, line in enumerate(fileinput.input(targetFile, inplace=True)):
        if i + 1 == lineToUpdate:
            print(lineFormat.format(inidata = iniData))
        else:
            print(line, end='')

if __name__ == '__main__':
    outputTargetFileWithSubstituted(readINIData())
    sys.stdout.write('Updated: ' + targetFile + '\n')
