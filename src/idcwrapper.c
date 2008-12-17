/*
 *
 * Copyright 2008 by Éverton Ribeiro <nuxlli@gmail.com>, Brasil.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of copyright holders not be
 * used in advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.  The copyright holders
 * make no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without express or
 * implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <xf86.h>

_X_EXPORT void
xf86usleep(usec)
    unsigned long usec;
{
#if (defined(SYSV) || defined(SVR4)) && !defined(sun)
    syscall(3112, (usec) / 1000 + 1);
#else
    usleep(usec);
#endif
}

_X_EXPORT void*
xf86memset(void* s, int c, size_t n)
{
	return(memset(s,c,(size_t)n));
}

/**
 * Module versioning information
 */
static XF86ModuleVersionInfo IDCWrapperVersionRec = {
    "idcwrapper",
    MODULEVENDORSTRING,
    MODINFOSTRING1,
    MODINFOSTRING2,
    XORG_VERSION_CURRENT,
    PACKAGE_VERSION_MAJOR, PACKAGE_VERSION_MINOR, PACKAGE_VERSION_PATCHLEVEL,
    ABI_CLASS_XINPUT,
    ABI_XINPUT_VERSION,
    MOD_CLASS_XINPUT,
    {0, 0, 0, 0}
};

/* module */
static void IDCWrapperUnplug(pointer p) {}
static pointer IDCWrapperPlug(pointer module,
                          pointer options,
                          int     *errmaj,
                          int     *errmin) { return module; }

/**
 * Module control. Fields are used when module is loaded/unloaded.
 */
_X_EXPORT XF86ModuleData idcwrapperModuleData = {
    &IDCWrapperVersionRec,
    IDCWrapperUnplug,
    IDCWrapperPlug
};
