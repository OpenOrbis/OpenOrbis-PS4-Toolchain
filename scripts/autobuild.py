#!/usr/bin/python
import sys, os, ntpath, platform, shutil
from pprint import pprint
from subprocess import call
from shutil import copyfile
import xml.etree.ElementTree as ET

print('\nAutobuild Helper\nBy CrazyVoid\n')

OO_SDK_PATH = os.environ['OO_PS4_TOOLCHAIN']
cwdPath = os.getcwd()
orbieConfig_volumets = "2018-01-30 04:20:11"
orbieConfig_appname = "Example Homebrew"
orbieConfig_contentid = "EP0000-TEST80080_00-XXXXXX000XXXXXXX"
orbieConfig_passcode = "00000000000000000000000000000000"
orbieConfig_storage_type = "digital50"
orbieConfig_app_type = "freemium"

def printHelp():
	print('Usage : autobuild.py\n')
	print('absetting.xml needs to be in the root of the folder you call the script from!\n\n')



#Check if there the proper amount of args
if len(sys.argv) != 2:
	if(os.path.exists("absetting.xml")):
		input_setting_file = "absetting.xml"
	else:
		printHelp()
		sys.exit(0)
else:
	if(sys.argv[1] == "-help"):
		printHelp()
		sys.exit(0)
	elif(sys.argv[1] == "-template"):
		print("TEMPLATE PRINT OUT\n")
		sys.exit(0)
	else:
		if(os.path.exists(sys.argv[1])):
			input_setting_file = sys.argv[1]
		else:
			print("[ERROR] " + sys.argv[1] + " - does not exist\n")
			sys.exit(1)

current_os = platform.system()

# Check which os we are on to support other os
if current_os == "Linux":
    # Linux Enviroment Vars
    TOOL_CREATE_EBOOT_PATH = OO_SDK_PATH + "/bin/linux/create-eboot"
    TOOL_CREATE_LIB_PATH = OO_SDK_PATH + "/bin/linux/create-lib"
    TOOL_MAKE_FSELF_PATH = OO_SDK_PATH + "/bin/linux/create-eboot"
    TOOL_PKGTOOLS_PATH = OO_SDK_PATH + "/bin/linux/PkgTool.Core"
    TOOL_TRAPHOUSE_PATH = OO_SDK_PATH + "/bin/linux/Traphouse"
    print("OS Detected : Linux\n")
elif current_os == "Windows":
    # Windows Enviroment Vars 
    print("Need to add windows suport later on\nExiting out...\n")
    TOOL_CREATE_EBOOT_PATH = OO_SDK_PATH + "/bin/windows/create-eboot.exe"
    TOOL_CREATE_LIB_PATH = OO_SDK_PATH + "/bin/windows/create-lib.exe"
    TOOL_MAKE_FSELF_PATH = OO_SDK_PATH + "/bin/windows/create-eboot.exe"
    TOOL_PKGTOOLS_PATH = OO_SDK_PATH + "/bin/windows/PkgTool.exe"
    TOOL_TRAPHOUSE_PATH = OO_SDK_PATH + "/bin/windows/Traphouse.exe"
    print("OS Detected : Windows\n")
elif current_os == "Macos":
	print("OS Detected : Macos\n")
	print("Macos not supported at the moment...\n")
	exit(4)
else:
	print("UNSUPPORTED OS DETECTED - Exiting...\n");
	exit(4)
	
DATA_PKG_FOLDER = OO_SDK_PATH + "/bin/data/"
			
print("Attempting to load setting file : " + input_setting_file + "\n")

with open(input_setting_file, 'rt') as f:
    tree = ET.parse(f)
    root = tree.getroot()
	
# Get setting info from file
setting_app_title = root.find('APP_TITLE').text
setting_app_title_id = root.find('APP_TITLE_ID').text
setting_app_content_id = root.find('APP_CONTENT_ID').text
setting_app_category = root.find('APP_CATEGORY').text
setting_app_type = root.find('APP_TYPE').text
setting_app_ver = root.find('APP_VER').text
setting_pkg_eboot_location = root.find('PKG_EBOOT_LOCATION').text
setting_pkg_assets_folder = root.find('PKG_ASSETS_FOLDER').text
setting_pkg_modules_folder = root.find('PKG_MODULES_FOLDER').text
setting_pkg_system_folder = root.find('PKG_SYSTEM_FOLDER').text
setting_pkg_ignore_files = root.find('PKG_IGNORE_FILES').text
setting_pkg_passcode = root.find('PKG_PASSCODE').text 
setting_pkg_storage_type = root.find('PKG_STORAGE_TYPE').text
setting_pkg_app_type = root.find('PKG_APP_TYPE').text
setting_build_folder = root.find('BUILD_FOLDER').text
setting_build_filename = root.find('BUILD_FILENAME').text
setting_attribute = root.find('ATTRIBUTE').text
setting_format = root.find('FORMAT').text
setting_parental_level = root.find('PARENTAL_LEVEL').text 
setting_remote_play_key_assign = root.find('REMOTE_PLAY_KEY_ASSIGN').text
setting_system_ver = root.find('SYSTEM_VER').text
setting_version = root.find('VERSION').text 

print("BUILD FOLDER : " + str(setting_build_folder) + "\n")


def createBuildFolders():
	os.makedirs(setting_build_folder)
	os.makedirs(setting_build_folder + "/tmppkg")
	os.makedirs(setting_build_folder + "/tmppkg/assets")
	os.makedirs(setting_build_folder + "/tmppkg/sce_module")
	os.makedirs(setting_build_folder + "/tmppkg/sce_sys")

	
def buildPKGProcess():
	# Check if build folder exist, if not create it!
	print("[INFO] Checking if folder : " + setting_build_folder + "\n")
	if not os.path.exists(setting_build_folder):
		createBuildFolders()
		print('[INFO] Creating Folder '+setting_build_folder+'\n')
	else:
		print('[INFO] '+setting_build_folder+' Folder exists\n');
		#shutil.rmtree(setting_build_folder)
		createBuildFolders()
		
	pkg_assfiles = ""
	pkg_assetfiles = []
	copy_assets = False
	copy_modules = False
	copy_system = False
	pkg_assets_files_count = 0
	pkg_module_files_count = 0
	pkg_system_files_count = 0


	# Check if assets folder exist, if it does, add entrys
	if(os.path.exists(setting_pkg_assets_folder)):
		# Add files to list of files to build into pkg 
		for pkg_assets_file in os.listdir(setting_pkg_assets_folder):
			pkg_assets_files_count += 1
			print("Adding file to pkg build directory : " + pkg_assets_file)
			copyfile("pkg_assets/" + pkg_assets_file, setting_build_folder + "/tmppkg/assets/" + pkg_assets_file)
			pkg_assfiles += '\t\t<file targ_path="assets/' + pkg_assets_file + '"/>\n'
			pkg_assetfiles.append('\t\t<file targ_path="assets/' + pkg_assets_file + '"/>\n')
		if(pkg_assets_files_count > 0):
			copy_assets = True

	if(os.path.exists(setting_pkg_modules_folder)):
		for pkg_module_file in os.listdir(setting_pkg_modules_folder):
			pkg_module_files_count += 1
			print("Adding file to pkg build directory : " + pkg_module_file)
			copyfile("pkg_module/" + pkg_module_file, setting_build_folder + "/tmppkg/sce_module/" + pkg_module_file)
			pkg_assfiles += '\t\t<file targ_path="sce_module/' + pkg_module_file + '"/>\n'
			pkg_assetfiles.append('\t\t<file targ_path="sce_module/' + pkg_module_file + '"/>\n')
		if(pkg_module_files_count > 0):
			copy_modules = True

	if(os.path.exists(setting_pkg_system_folder)):
		for pkg_system_file in os.listdir(setting_pkg_system_folder):
			pkg_system_files_count += 1
			copyfile("pkg_system/" + pkg_system_file, setting_build_folder + "/tmppkg/sce_sys/" + pkg_system_file)
			pkg_assfiles += '\t\t<file targ_path="sce_sys/' + pkg_system_file + '"/>\n'
			pkg_assetfiles.append('\t\t<file targ_path="sce_sys/' + pkg_system_file + '"/>\n')
		if(pkg_system_files_count > 0):
			copy_system = True

	# if libc.prx is not inside the tmppkg folder, copy it from our bin/data
	if(os.path.exists(setting_build_folder + "/tmppkg/sce_module/libc.prx") == 0):
		copyfile(DATA_PKG_FOLDER + "modules/libc.prx", setting_build_folder + "/tmppkg/sce_module/libc.prx")
		pkg_assfiles += '\t\t<file targ_path="sce_module/libc.prx"/>\n'

	# if libSceFios2.prx is not inside the tmppkg folder, copy it from our bin/data
	if(os.path.exists(setting_build_folder + "/tmppkg/sce_module/libSceFios2.prx") == 0):
		copyfile(DATA_PKG_FOLDER + "modules/libSceFios2.prx", setting_build_folder + "/tmppkg/sce_module/libSceFios2.prx")
		pkg_assfiles += '\t\t<file targ_path="sce_module/libSceFios2.prx"/>\n'
		
	# if param.sfo is not inside the tmppkg folder, copy it from our bin/data
	if(os.path.exists(setting_build_folder + "/tmppkg/sce_sys/param.sfo") == 0):
		copyfile(DATA_PKG_FOLDER + "param.sfo", setting_build_folder + "/tmppkg/sce_sys/param.sfo")
		pkg_assfiles += '\t\t<file targ_path="sce_sys/libc.prx"/>\n'
			
	if(os.path.exists(setting_build_folder + "/tmppkg/sce_sys/icon0.png") == 0):
		copyfile(DATA_PKG_FOLDER + "icon0.png", setting_build_folder + "/tmppkg/sce_sys/icon0.png")
		pkg_assfiles += '\t\t<file targ_path="sce_sys/icon0.png"/>\n'
		
	if(os.path.exists(setting_build_folder + "/tmppkg/sce_sys/pic0.png") == 0):
		copyfile(DATA_PKG_FOLDER + "pic0.png", setting_build_folder + "/tmppkg/sce_sys/pic0.png")
		pkg_assfiles += '\t\t<file targ_path="sce_sys/pic0.png"/>\n'
		
	# Check for eboot.bin exists or not...		
	if(os.path.exists("eboot.bin")):
		copyfile("eboot.bin", setting_build_folder + "/tmppkg/eboot.bin")
		pkg_assfiles += '\t\t<file targ_path="eboot.bin"/>'
	else:
		print("[ERROR] eboot.bin must exist for autobuild.py to run\n")
		exit(4)

	# Open the template GP4 File
	template_gp4_fh = open(DATA_PKG_FOLDER + "template.gp4")
	template_gp4_content = template_gp4_fh.read()
	template_gp4_fh.close()

	template_gp4_content = template_gp4_content.replace("{CONTENT_ID}", setting_app_content_id)
	template_gp4_content = template_gp4_content.replace("{PASSCODE}", setting_pkg_passcode)
	template_gp4_content = template_gp4_content.replace("{STORAGE_TYPE}", setting_pkg_storage_type)
	template_gp4_content = template_gp4_content.replace("{APP_TYPE}", setting_pkg_app_type)
	template_gp4_content = template_gp4_content.replace("{FILES}", pkg_assfiles)	

	write_gp4_fh = open(setting_build_folder + "/tmppkg/template.gp4", "w")
	write_gp4_fh.write(template_gp4_content)
	write_gp4_fh.close()

	print("COMMAND : " + TOOL_PKGTOOLS_PATH + " pkg_build " + cwdPath +"/"+ setting_build_folder + "/tmppkg/template.gp4 " + cwdPath +"/"+ setting_build_folder) 
	os.system(TOOL_PKGTOOLS_PATH + " pkg_build " + cwdPath +"/"+ setting_build_folder + "/tmppkg/template.gp4 " + cwdPath +"/"+ setting_build_folder)
