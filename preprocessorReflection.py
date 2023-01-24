import os
import glob

path = "./Source"
ignoreFiles = ["wae-reflect.h","build"]

#os.chdir(path)

# Iterate through the folder recursively.
for filename in glob.iglob(path + "/**/*.c", recursive=True):
    print(filename)

def parseFile(filename):
    file = open(filename)
    data = file.read()
    file.close()

    for c in 
