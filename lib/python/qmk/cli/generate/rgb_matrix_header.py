###
# Generates an RGB Matrix header file with all available effects to disable.

# Copyright (C) 2021 agodinhost@

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
###

import os
import pathlib

from milc import cli
from qmk.path import normpath

QMK_HOME = os.getcwd()
RGB_MATRIX_FOLDER = QMK_HOME + '/quantum/rgb_matrix_animations'
RGB_MATRIX_HEADER = RGB_MATRIX_FOLDER + '/disable_all_rgb_matrix.h'
RGB_MATRIX_PREFIX = "DISABLE_RGB_MATRIX_"

def info(message, *args):
    if not cli.args.quiet:
        cli.log.info(message, *args)

def warning(message, *args):
    if not cli.args.quiet:
        cli.log.warning(message, *args)

def error(message, *args):
    cli.log.error(message, *args)
    exit(0)

def getHeaders(input):
    files = pathlib.Path(input).glob("*.h")
    headers = []
    for file in files:
        if os.path.isfile(file):
            headers.append(file)
    if not headers:
        error('there are no header files into the input folder {fg_red}%s!', input)
    return headers

def getDefine(header):
    define = None
    try:
        fHeader = open(header, "r")
        for line in fHeader:
            pos = line.find(RGB_MATRIX_PREFIX)
            if pos > -1:
                tmp = line[pos:]
                define = tmp.split()[0].replace(')','')
                break
        fHeader.close()
    except IOError:
        error('error opening file: {fg_red}%s', header)
    return define

def getTemplate(input):
    template = """\
/* Copyright 2021 agodinhost@
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file was auto-generated by:
 *    `qmk generate-rgb-matrix-header`
 */

#pragma once

"""
    headers = getHeaders(input)
    for header in headers:
        define = getDefine(header)
        if define:
            template += "#define {!s} /* {!s} */\n".format(define.ljust(50), header.name)
        else:
            warning('header file {fg_yellow}%s without a DISABLE define.', header.name)
    return template

def writeFile(output, template):
    try:
        fOutput = open(output, "a")
        fOutput.write(template)
        fOutput.close()
        info('file {fg_green}%s created.', output)
    except IOError:
        error('Error creating file {fg_red}%s!', output)

@cli.argument('-i', '--input', arg_only=True, type=normpath, default=RGB_MATRIX_FOLDER, help='The input folder to scan')
@cli.argument('-o', '--output', arg_only=True, type=normpath, default=RGB_MATRIX_HEADER, help='The output file to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.subcommand('Generates an RGB Matrix header file with all available effects to disable.')
def generate_rgb_matrix_header(cli):

    input = cli.args.input
    if os.path.exists(input):
        info('input folder: {fg_green}%s', input)
    else:
        error('input folder {fg_red}%s NOT FOUND!', input)

    output = cli.args.output
    if os.path.exists(output):
        try:
            os.remove(output)
        except IOError:
            error('Error deleting file {fg_red}%s!', output)

    template = getTemplate(input)
    writeFile(output, template)
