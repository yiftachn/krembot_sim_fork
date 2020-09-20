
# Install Krembot Workspace

The first time you use the simulator to run your own krembot program, you will need to create your own
folder, in your own home directory. Our recommendation is to use a separate git repository for your work,
but this is up to you.  **Do NOT use a folder inside this krembot_sim git repository**, as it only 
contains the simulator and some example code. 

Choose a location for your workspace.  For instance, in your home folder, you could make a krembot_ws
folder.  Copy the krembot_ws folder from the krembot_sim git to create the new workspace. 

Here's an example (we assume you followed the installation instructions):

````
cd
cp -r $KREMBOT_SIM_PATH/krembot_ws krembot_ws
````



Build your workspace

````
./krembot_ws/scripts/compile.sh	
````

After, follow the instraction in the workspace README.