# //////////////////////////////////////////////////////////////////////////////
# // File:     Name:        c_mmap.py                                         //
# //           Language:    Python 3                                          //
# //                                                                          //
# // Details:  This file contains memory map commands.                        //
# //                                                                          //
# // Author:   Name:    Marijn Verschuren, Ralph Vreman                       //
# //           Email:   marijnverschuren3@gmail.com                           //
# //                                                                          //
# // Date:     2023-10-25                                                     //
# //////////////////////////////////////////////////////////////////////////////

import mmap
import os

WORK_DIR = os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + "/../..")

"""
Loads a memory map.
"""
def load_map(ctx):
    cmdl = len(ctx['cmd'])

    if cmdl < 3:
        print(f"Error: no path specified to load.")
        return

    fpath = f"{WORK_DIR}/{ctx['cmd'][2]}"

    if not os.path.exists(fpath):
        print("Error: the specified memory map does not exist.")
        return

    # Prepare mmap
    ctx['app']['mmap'] = mmap.parse(fpath)
    
    print(f'Memory map loaded from "{fpath}"')


subcmd_list = {
    'load': load_map
}

"""
Sub-command not found handler.
"""
def cmd_not_found():
    print("invalid subcommand.")

"""
Main MMAP command handler.
"""
def cmd_mmap(ctx):
    cmdl = len(ctx['cmd'])

    if cmdl < 2:
        print(f"Usage: mmap <command> [arguments]\n\
\n\
Valid commands are:\n\
    load <path> - Loads a memory map file.\n\
    view        - Views the loaded memory map.\n\
    ")
    
    subcmd_list.get(ctx['cmd'][1], cmd_not_found)(ctx)
