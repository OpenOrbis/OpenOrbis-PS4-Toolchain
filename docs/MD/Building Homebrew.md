# Building Homebrew

This document will contain all the information necessary for taking a built `eboot.bin` file from a compiled project, and packing it up for installation on the PS4.



## Step 1: Create a package using maxton's LibOrbisPkg

Using PkgEditor.exe (found in `/bin/windows/PkgEditor.exe`), create a new .GP4 template file.

![](https://i.imgur.com/eC6pBgO.png)



## Step 2: Set metadata info

The content ID is of the format `XXXXXX-CUSA00000_00-ZZZZZZZZZZZZZZZZ`. If you want the app to be compatible with the store when it's ready, follow the format of `IV0000-BREWXXXXX_00-YYYYYYYYYY000000`. The app ID (XXXXXX) will be assigned when a package is submitted for review and is accepted into the store. Feel free to enter whatever for the "Y" section.

The passcode you may as well leave as null, as it won't protect your packages anyway as it's not signed with a proper private key.

Package type should be set to `Game Package`.

![](https://i.imgur.com/QfMjToF.png)



## Step 3: Create image

The package image contains all the contents that will be mounted in the application sandbox at time of launch. Failure to set this up properly will result in your app either:

1) Prompting an error before launching, or

2) Causing an error or crash after launching

The below files are *required* for every package:

```
|- sce_sys
   |- icon0.png
   |- param.sfo
|- eboot.bin
```



### icon0

The `icon0` file should be a 512x512 PNG **without alpha transparency**. It must be a 24-bit PNG, not a 32-bit.



### param.sfo

The `param.sfo` file can be created through the same PkgEditor tool by going to `File -> New -> SFO File`. Using the guided editor, set your SFO type to `gd` - Game Digital Application. The content ID should match the content ID set in the package. The title is whatever you want the title of the app to be on the homescreen. Version and App Version is generally left at `1.00`. App Type can be left unspecified or set to `1 - Paid standalone full app`.

Generally the download data size and attributes do not need to be changed unless you're doing something that requires PSVR or something along those lines.

![](https://i.imgur.com/IVBouFR.png)



### eboot.bin

This file will come from your project output, typically in the root directory / in the same directory as the solution or Makefile.



#### Note on 3rd party files

If your homebrew app uses any files via the filesystem, those files **must** be included in the package so they're mounted in the sandbox. This is if you're decoding an image or a sound file for example. In your app, `/App0/` refers to the root directory of your package, so make sure everything is relative to that.



## Step 4: Profit?

If you've done the previous 3 steps correctly, you should be able to hit the "Build PKG" button and successfully save a package file to wherever you choose. You can now load this package file onto a USB, and install it through the "Debug Menu" on a jailbroken PS4!