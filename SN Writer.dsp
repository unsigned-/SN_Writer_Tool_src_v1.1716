# Microsoft Developer Studio Project File - Name="SN Writer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SN Writer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SN Writer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SN Writer.mak" CFG="SN Writer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SN Writer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SN Writer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SN Writer - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Output"
# PROP Intermediate_Dir "Output"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I ".\Execute" /I ".\Form\ScanData" /I ".\Form\AutoGen" /I ".\Form\Identify" /I ".\Form\About" /I ".\Form\SystemConfig" /I ".\Form\FileSel" /I ".\MtkLib\AT_cmd\inc" /I ".\Extra\CBtnST" /I ".\MtkLib\Brom\inc" /I ".\MtkLib\DebugTrace\inc" /I ".\MtkLib\SNFstream\inc" /I ".\Common" /I ".\MtkLib\Eboot\inc" /I ".\MtkLib\Meta\inc" /I ".\MtkLib\Security\inc" /I ".\MtkLib\USBSwitchTool\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 shlwapi.lib "./mtklib/meta/lib/*.lib" "./mtklib/Eboot/lib/*.lib" "./mtklib/Security/lib/*.lib" "./mtklib/SNFstream/lib/*.lib" "./mtklib/DebugTrace/lib/*.lib" "./mtklib/usbswitchtool/lib/*.lib" /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SN Writer - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Output"
# PROP Intermediate_Dir "Output"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gi /GX /ZI /Od /I ".\\" /I ".\SNbase\inc" /I ".\Execute" /I ".\Extra\CBtnST" /I ".\Form\About" /I ".\Form\AutoGen" /I ".\Form\ScanData" /I ".\Form\Identify" /I ".\Form\FileSel" /I ".\Form\SystemConfig" /I ".\MtkLib\AT_cmd\inc" /I ".\CBtnST" /I ".\MtkLib\Brom\inc" /I ".\MtkLib\DebugTrace\inc" /I ".\MtkLib\SNFstream\inc" /I ".\Common" /I ".\MtkLib\Eboot\inc" /I ".\MtkLib\Meta\inc" /I ".\MtkLib\Security\inc" /I ".\MtkLib\USBSwitchTool\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Fp"Debug/SN_Station.pch" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 shlwapi.lib "./mtklib/meta/lib/*.lib" "./mtklib/Eboot/lib/*.lib" "./mtklib/Security/lib/*.lib" "./mtklib/SNFstream/lib/*.lib" "./mtklib/DebugTrace/lib/*.lib" "./mtklib/usbswitchtool/lib/*.lib" /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none /incremental:no

!ENDIF 

# Begin Target

# Name "SN Writer - Win32 Release"
# Name "SN Writer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Common_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Common\Common.cpp
# End Source File
# End Group
# Begin Group "Exec_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Execute\FPexc.cpp
# End Source File
# Begin Source File

SOURCE=.\Execute\SNbase.cpp
# End Source File
# Begin Source File

SOURCE=.\Execute\SPexc.cpp
# End Source File
# End Group
# Begin Group "MtkLib_SRC"

# PROP Default_Filter ""
# Begin Group "ATCmd_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\AT_cmd\src\AtProcess.cpp
# End Source File
# Begin Source File

SOURCE=.\MtkLib\AT_cmd\src\rs232Module.cpp
# End Source File
# End Group
# Begin Group "DebugTrace_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\DebugTrace\src\xboot_debug.cpp
# End Source File
# End Group
# Begin Group "Security_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\Security\src\AUTH.cpp
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\src\SCERT.cpp
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\src\SLA.cpp
# End Source File
# End Group
# End Group
# Begin Group "Form_SRC"

# PROP Default_Filter ""
# Begin Group "FileSel_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\FileSel\fileseldlg.cpp
# End Source File
# End Group
# Begin Group "Identify_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\Identify\ChgPasswdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Form\Identify\VerifyPasswdDlg.cpp
# End Source File
# End Group
# Begin Group "ScanData_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\ScanData\ScanData.cpp
# End Source File
# End Group
# Begin Group "SystemConfig_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\SystemConfig\SystemConfig.cpp
# End Source File
# End Group
# Begin Group "About_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\About\AboutSNDlg.cpp
# End Source File
# End Group
# Begin Group "AutoGen_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\AutoGen\autogendlg.cpp
# End Source File
# End Group
# End Group
# Begin Group "Extra_SRC"

# PROP Default_Filter ""
# Begin Group "BtnST_SRC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Extra\CBtnST\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\Extra\CBtnST\CeXDib.cpp
# End Source File
# Begin Source File

SOURCE=.\Extra\CBtnST\ShadeButtonST.cpp
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Encryption.cpp
# End Source File
# Begin Source File

SOURCE=".\SN Writer.cpp"
# End Source File
# Begin Source File

SOURCE=".\SN WriterDlg.cpp"
# End Source File
# Begin Source File

SOURCE=".\StdAfx.cpp"
# ADD CPP /Yc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Common_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Common\Common.h
# End Source File
# End Group
# Begin Group "Exec_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Execute\FPexc.h
# End Source File
# Begin Source File

SOURCE=.\Execute\SNbase.h
# End Source File
# Begin Source File

SOURCE=.\Execute\SPexc.h
# End Source File
# End Group
# Begin Group "MtkLib_HDR"

# PROP Default_Filter ""
# Begin Group "Meta_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\brom.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\com_enum.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\DOWNLOAD.H
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\external_memory_setting.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\flashtool.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\flashtool_api.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\flashtool_handle.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\HdcpEncryption.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\meta.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\mtk_mcu.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\mtk_resource.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\mtk_status.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\rom_setting.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\sp_brom.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\SP_META_Wrapper.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\spmeta.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\wm_meta_cct.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\wm_meta_cct_6238.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Meta\inc\xboot.h
# End Source File
# End Group
# Begin Group "ATCmd_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\AT_cmd\inc\AtProcess.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\AT_cmd\inc\rs232Module.h
# End Source File
# End Group
# Begin Group "DebugTrace_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\DebugTrace\inc\Mdebug.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\DebugTrace\inc\xboot_debug.h
# End Source File
# End Group
# Begin Group "Security_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\Security\inc\AUTH.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\inc\des.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\inc\SCERT.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\inc\SLA.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\Security\inc\SLA_Challenge.h
# End Source File
# End Group
# Begin Group "SNFstream_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\SNFstream\inc\AutoGen.h
# End Source File
# Begin Source File

SOURCE=.\MtkLib\SNFstream\inc\SNFstream.h
# End Source File
# End Group
# Begin Group "USBSwitchTool_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MtkLib\USBSwitchTool\inc\USBSwitchDLLibrary.h
# End Source File
# End Group
# End Group
# Begin Group "Form_HDR"

# PROP Default_Filter ""
# Begin Group "FileSel_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\FileSel\fileseldlg.h
# End Source File
# End Group
# Begin Group "Identify_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\Identify\ChgPasswdDlg.h
# End Source File
# Begin Source File

SOURCE=.\Form\Identify\VerifyPasswdDlg.h
# End Source File
# End Group
# Begin Group "ScanData_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\ScanData\ScanData.h
# End Source File
# End Group
# Begin Group "SystemConfig_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\SystemConfig\SystemConfig.h
# End Source File
# End Group
# Begin Group "About_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\About\AboutSNDlg.h
# End Source File
# End Group
# Begin Group "AutoGen_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Form\AutoGen\autogendlg.h
# End Source File
# End Group
# End Group
# Begin Group "Extra_HDR"

# PROP Default_Filter ""
# Begin Group "BtnST_HDR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Extra\CBtnST\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\Extra\CBtnST\CeXDib.h
# End Source File
# Begin Source File

SOURCE=.\Extra\CBtnST\ShadeButtonST.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Encryption.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=".\SN Writer.h"
# End Source File
# Begin Source File

SOURCE=".\SN WriterDlg.h"
# End Source File
# Begin Source File

SOURCE=".\StdAfx.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\FAIL.bmp
# End Source File
# Begin Source File

SOURCE=.\res\manifest.xml
# End Source File
# Begin Source File

SOURCE=.\res\PASS.bmp
# End Source File
# Begin Source File

SOURCE=".\res\SN Writer.ico"
# End Source File
# Begin Source File

SOURCE=".\SN Writer.rc"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
