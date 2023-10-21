# Tool to generate current build information for use in the kernel
import subprocess
import datetime
import os

WORK_DIR = os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + "/..")
command = "git log -n 1 --pretty=format:%h"

result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)

# Check the result
if result.returncode == 0:
    # Generate header file with info
    commit = result.stdout.strip()
    print(f"Got commit hash: {commit}, writing build.h...")
     
    with open(WORK_DIR + "/src/build.h", 'w') as file:
        dt = datetime.datetime.now()
        form_dt = dt.strftime('%Y-%m-%d %H:%M:%S')

        file.write("#ifndef __BUILD_H\n")
        file.write("#define __BUILD_H\n\n")
        file.write(f"// Generated at {form_dt}\n")
        file.write(f"#define B_GIT_HASH \"{commit}\"\n")
        file.write(f"#define B_COMPTIME_START \"{form_dt}\"\n")
        file.write("\n#endif")

    exit(0)
else:
    print("Git command failure")
    exit(1)