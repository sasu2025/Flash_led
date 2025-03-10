# This script is licensed under BSD License, see file LICENSE.txt.
#
# (c) TASKING Germany GmbH, 2023
 
import isystem.connect as ic
import os
 
winidea_path = "C:\\iSYSTEM\\winIDEA9\\winIDEA.exe"
winidea_id = "180999"


def test_begin_program():
    conn_mgr = ic.ConnectionMgr()
    conn_mgr.connect(ic.CConnectionConfig().instanceId(winidea_id))
    sess_ctrl = ic.CSessionCtrl(conn_mgr)
    execCtrl = ic.CExecutionController(conn_mgr)
    wksCtrl = ic.CWorkspaceController(conn_mgr)
    
    # Changed: Set the working directory to the correct folder (Option 2 change)
    os.chdir("C:\\Workspace\\s32\\CI_CD_Test\\Debug_FLASH")
    print("New working directory:", os.getcwd())
    
    # Changed: Construct the workspace file path relative to the new working directory (Option 2 change)
    wksFilePath = os.getcwd() + '\\debug_s32k.xjrf'
    print("Using workspace file:", wksFilePath)
    
    print("Opening original workspace...")
    wksCtrl.open(wksFilePath)
    sess_ctrl.begin_prepare()
    
    if execCtrl.hotAttach() == 0:
       print(f"Hot attach succeeded, winIDEA is connected.")
    else:
       print(f"Hot attach failed, winIDEA is not connected.")
     
    sess_ctrl.begin_program()
    print("Programming success")
    
    execCtrl.runUntilFunction('main')
    execCtrl.waitUntilStopped()
    print("Stopped at Main")
    
    execCtrl.run()
    isRunning = execCtrl.getCPUStatus(False).isRunning()
    print(f"Is CPU in `RUN` state: {isRunning}")
    
    if execCtrl.hotDetach() == 0:
       print(f"Hot detach succeeded, winIDEA is disconnected.")
    else:
        print(f"Hot Detach failed, winIDEA is not connected.")

    print("Disconnecting...")
    conn_mgr.disconnect_close(bSaveAll=False)
    print(f"\tIs connected: {conn_mgr.isConnected()}")
   
if __name__ == "__main__":
    test_begin_program()
