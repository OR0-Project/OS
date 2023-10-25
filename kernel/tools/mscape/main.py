# //////////////////////////////////////////////////////////////////////////////
# // File:     Name:        main.py                                           //
# //           Language:    Python 3                                          //
# //                                                                          //
# // Details:  Main entry file for memscape.                                  //
# //                                                                          //
# // Author:   Name:    Marijn Verschuren, Ralph Vreman                       //
# //           Email:   marijnverschuren3@gmail.com                           //
# //                                                                          //
# // Date:     2023-10-25                                                     //
# //////////////////////////////////////////////////////////////////////////////

import os
import sys

MOD_DIR = os.path.abspath(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(f"{MOD_DIR}/cmd")

import generics
import manipl
import tools
import mmap

# Vars
WORK_DIR = os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + "/../..") + "/work"
DUMP_NAME = "memory.dmp"
DUMP_PATH = f"{WORK_DIR}/dumps/{DUMP_NAME}"

# Context
fd = None # File
DMP = None # Dump contents
cur_addr = 0
fsize = 0

# Command List
# --------------------------------
cmd_list = {
    # Basic commands
    'exit': generics.cmd_exit,
    'clear': generics.cmd_clear,
    'offset': generics.cmd_offset,

    # I/O
    'read': manipl.cmd_read,
    'dump': manipl.cmd_dump,

    # Utility commands
    'ord': tools.cmd_ord
}
# --------------------------------

# Reads the dump
def opendmp():
    global fd
    global fsize
    fd = open(DUMP_PATH, mode="rb")
    fsize = os.path.getsize(DUMP_PATH)
    print("-- ")
    print(f"In Dump: {DUMP_PATH}")
    print(f"Size: {(fsize / 1024 / 1024):.2f} MB")
    print("-- \n")

# Shell loop
def shl():
    global cur_addr

    while True:
        try:
            cmd_line = input(f"{DUMP_NAME} [{hex(cur_addr)}] > ")
            cmd = cmd_line.split(' ')

            # Command context
            context = {
                'fd': fd,
                'fsize': fsize,
                'cmd_line': cmd_line,
                'cmd': cmd,
                'offset': cur_addr
            }

            # Execute command
            cmd_list.get(cmd[0], generics.cmd_not_found)(context)

            # Keep cur address synchronized
            cur_addr = context['offset']
        except Exception as e:
            print(e)

# Entry point
def main():
    print("MemScape 1.0.0")
    if not os.path.exists(DUMP_PATH):
        print("No dump has been made. Please run the dumping tool and rerun the program again.")
        return

    opendmp()
    shl()

#main()

mmap.parse("tools/kernel.mmap")