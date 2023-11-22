# networking-authenticator

Before you start, make sure there are not spaces in the absolute project path. This will cause one of postbuildcommands to fail, resulting in the project not starting.

Also don't forget to add the sql files to MySQL and start a service.

To generate the .sln, double click the GenerateFiles WBF (Windows Bacth File). This will open a command prompt, creating the sln file.
On startup, 'Nebula' should be the startup project and Debug should be the active mode. This is all done with premake, so this is default. The project only contains a debug mode, since the text displayed is created with the SPDLog library, which only works in debug mode in this project.

To start the program, Build the complete solution inside visual studio. Once all the libraries are build, Start the three projects in the following order:
- Authenticator
- Chat_Server
- Chat_Client
The client is the only project that needs user input.

Follow the steps to join a room and chat. To leave, type 'E' and click enter. This will put you back in the room selection menu.
The build solutions can be found in the 'bin' folder.

