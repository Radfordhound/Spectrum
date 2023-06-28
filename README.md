# Spectrum

Spectrum is a crazy DLL mod for Sonic Lost World on PC that aims to transform the game into an enhanced port of Sonic Colors!

## Building

You need Visual Studio 2022 with the C++ stuff installed.

You'll also need some dependencies. You should place them next to the Spectrum folder, such that you end up with a folder structure that looks like this:

- [HookHelpers](https://github.com/Radfordhound/HookHelpers)
- [OpenLW](https://github.com/Radfordhound/OpenLW)
- Spectrum

Once you have all of that, you can just open Spectrum.sln in Visual Studio and hit "build".

NOTE: There's a post-build event that will try to copy the resulting Spectum.dll to the following path:
`E:\Program Files (x86)\Steam\steamapps\common\Sonic Lost World\mods\Spectrum(new)\files\`

This is a path specific to my machine. If you do not have this path on your machine, this post-build event will fail.

To change this, please right-click on the project in Visual Studio's "Solution Explorer", click "Properties", expand "Build Events", click "Post-Build Event", and change the path at the end of the command listed under "Command Line".
