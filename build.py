# To be manually configured.
commandToInject = "-I../Libraries/Pipsqueak/include"

#------------------------------------------------------

import os
import sys
import subprocess

# Discover files.

discoveredCPPs = ""
discoveredFolders = ""

for currentFolder, subFolders, files in os.walk(os.path.dirname(sys.argv[0])):
    for file in files:
        if file.endswith(".cpp"):
            discoveredCPPs += "\"" + currentFolder + "/" + file + "\" "
            print("Found: " + file)
    discoveredFolders += "-I\"" + currentFolder + "\" "

# Run final command.

finalCommand = f"clang {discoveredCPPs} {discoveredFolders} {commandToInject} -o Binaries/output.exe"
processObj = subprocess.run(finalCommand)

# Log.

print(" COMMAND: ")
print(finalCommand)

print(" OUT: ")
print(processObj.stdout)

print(" ERR: ")
print(processObj.stderr)

print("- Build Finished -")
input()