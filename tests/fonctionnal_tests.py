import sys
import subprocess
import os

exit_code = 0

def run_command(command):
    global exit_code

    try:
        subprocess.check_output(command, shell=True)
    except subprocess.CalledProcessError as e:
        exit_code = 84

run_command("ls -l | grep -v 'total' | grep -v '.result' > test01.result")
run_command("cat Makefile > test02.result")
run_command("ls -l | grep -v 'total' | grep -v '.result' | grep Makefile > test03.result")
run_command("ls -l | grep -v 'total' | grep -v '.result' | grep Makefile | wc -l > test04.result")

run_command("export LD_PRELOAD=./libasm.so:$LD_PRELOAD && ls -l | grep -v 'total' | grep -v '.result' > test11.result")
run_command("export LD_PRELOAD=./libasm.so:$LD_PRELOAD && cat Makefile > test12.result")
run_command("export LD_PRELOAD=./libasm.so:$LD_PRELOAD && ls -l | grep -v 'total' | grep -v '.result' | grep Makefile > test13.result")
run_command("export LD_PRELOAD=./libasm.so:$LD_PRELOAD && ls -l | grep -v 'total' | grep -v '.result' | grep Makefile | wc -l > test14.result")

def compare_results(file1, file2):
    global exit_code

    try:
        subprocess.check_output(f"diff {file1} {file2}", shell=True)
    except subprocess.CalledProcessError as e:
        print(file1 + " and " + file2 + " are different")
        exit_code = 84

compare_results("test01.result", "test11.result")
compare_results("test02.result", "test12.result")
compare_results("test03.result", "test13.result")
compare_results("test04.result", "test14.result")

if (exit_code == 0):
    print("All tests \033[92mpassed\033[0m")
else:
    print("Some tests \033[91mfailed\033[0m")

for file in os.listdir('.'):
    if file.endswith('.result'):
        os.remove(file)

sys.exit(exit_code)
