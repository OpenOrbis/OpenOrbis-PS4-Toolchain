#! /bin/sh

# Trust me, you don't want to modify this. It won't work.

is_llvm_installed=false

if [ -L "/usr/local/opt/llvm" ]; then # Checks for a pure version of LLVM, not the Apple one
  is_llvm_installed=true
fi

if [ "$is_llvm_installed" = false ] ; then
  CONTINUE="$(osascript -e 'display dialog "LLVM cannot be found.\n\nPure LLVM is required to compile homebrews, the Apple version would not work.\n\nWould you like to continue with the installation?" with icon caution buttons {"No", "Yes"} default button "Yes"')"
  if [ "$CONTINUE" = "button returned:No" ]; then
    exit 1
  fi
fi

exit 0
