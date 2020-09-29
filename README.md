# MultiComposite
Requires you to build it. It's not very performant

# Notes
Requires you to edit %AppData%/../Local/OpenVR/OpenVR.VRSettings and edit it to the build directory. You need to launch the games outside of steam currently because regardless of the VRClient, Steam closes the VR game that registers as a scene. I'll later publish some changes to allow you to select a prepare option to prepare to launch a game.
- NOTE: Requires you to launch this before editting the path settings
- NOTE: Requires you to copy the resources folder from your steamvr installation to where your build is
- NOTE: Requires you to have the build in a bin folder because of how the steamvr installation works. DM me if anything is off

# Credits
Organization of the OpenVR interfaces were possible because of the OpenComposite project on gitlab at https://gitlab.com/znixian/OpenOVR/
