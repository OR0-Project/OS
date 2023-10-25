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
import utils
import math

WORK_DIR = os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + "/../..")

"""
Loads a memory map.
"""
def subcmd_load(ctx):
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

"""
Views the currently loaded memory map.
"""
def subcmd_view(ctx):
    if ctx['app']['mmap'] == None:
        print("Error: no memory map is loaded.")
        return

    for g in ctx['app']['mmap'].groups:
        print(g)
        print(f"┌{'─' * 13}┬{'─' * 41}┬{'─' * 14}┬{'─' * 33}┐")
        print(f'│ Id          │ Range                                   │ Size         │ Description                     │ ')
        print(f'├─────────────┼─────────────────────────────────────────┼──────────────┼─────────────────────────────────┤ ')

        ranges = ctx['app']['mmap'].getByGroup(g)
        rangelen = len(ranges)

        for x in range(0, rangelen):
            rng = ranges[x]
            size = rng['_rhs'] - rng['_lhs']
            size_str = ""

            if size > (1024 * 1024): # 1 MiB
                size_str = f"{'{:.2f}'.format(size / 1024 / 1024)} MiB"
            else:
                size_str = f"{'{:.2f}'.format(size / 1024)} KiB"

            # Id
            print(f"│ {rng['id']}{(12 - len(rng['id'])) * ' '}", end = "")

            # Print range
            print(f'│ 0x{utils.zpad(rng["_lhs"], 16, use_hex = True)} - 0x{utils.zpad(rng["_rhs"], 16, use_hex = True)} │ ', end = "")

            # Size calc
            print(f'{size_str}{(13 - len(size_str)) * " "}│ ', end = "")

            # Description
            print(f'{rng["description"]}{(32 - len(rng["description"])) * " "}│')

            if (x + 1) < rangelen:
                print(f'├─────────────┼─────────────────────────────────────────┼──────────────┼─────────────────────────────────┤ ')
        
        print(f"└{'─' * 13}┴{'─' * 41}┴{'─' * 14}┴{'─' * 33}┘")
        print('')

# Command list
subcmd_list = {
    'load': subcmd_load,
    'view': subcmd_view
}

"""
Sub-command not found handler.
"""
def cmd_not_found(ctx):
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
