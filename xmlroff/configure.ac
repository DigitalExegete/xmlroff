dnl Process this file with autoconf to create configure.
set
# require autoconf 2.53
AC_PREREQ(2.53)


dnl The following version number definitions apply to xmlroff and libfo
dnl as a whole, so if changes occurred in any of them, they are all
dnl treated with the same interface and binary age.
dnl
dnl Making releases:
dnl   xmlroff_micro += 1;
dnl   xmlroff_interface_age += 1;
dnl if any functions have been added:
dnl   xmlroff_interface_age = 0
dnl if backwards compatibility has been broken:
dnl   xmlroff_binary_age = 0;
dnl   xmlroff_interface_age = 0;

m4_define([xmlroff_version_major],0)
m4_define([xmlroff_version_minor],6)
m4_define([xmlroff_version_micro],2)
m4_define([xmlroff_interface_age],0)
m4_define([xmlroff_version],
          [xmlroff_version_major.xmlroff_version_minor.xmlroff_version_micro])

dnl m4_define([xmlroff_binary_age],0)
m4_define([xmlroff_binary_age],m4_eval(100 * xmlroff_version_minor + xmlroff_version_micro))

AC_INIT([xmlroff XSL Formatter],
	xmlroff_version(),
	[http://xmlroff.org/newticket],
	xmlroff)
AM_CONFIG_HEADER(config.h)

XMLROFF_VERSION_MAJOR=xmlroff_version_major()
XMLROFF_VERSION_MINOR=xmlroff_version_minor()
XMLROFF_VERSION_MICRO=xmlroff_version_micro()
XMLROFF_VERSION=xmlroff_version()
XMLROFF_BINARY_AGE=xmlroff_binary_age()

if test -d .svn ; then
  extra=`svn info | grep Revision | sed 's+Revision: ++'`
  echo extra=$extra
  if test "$extra" != ""
  then
      XMLROFF_VERSION_EXTRA="-SVN$extra"
  fi
fi

AC_SUBST(XMLROFF_VERSION_MAJOR)
AC_SUBST(XMLROFF_VERSION_MINOR)
AC_SUBST(XMLROFF_VERSION_MICRO)
AC_SUBST(XMLROFF_VERSION)
AC_SUBST(XMLROFF_VERSION_EXTRA)
AC_SUBST(XMLROFF_INTERFACE_AGE)
AC_SUBST(XMLROFF_BINARY_AGE)

AC_DEFINE(XMLROFF_BINARY_AGE, xmlroff_binary_age(), [xmlroff binary age])
AC_DEFINE(XMLROFF_INTERFACE_AGE, xmlroff_interface_age(), [xmlroff interface age])
AC_DEFINE(XMLROFF_VERSION_MAJOR, xmlroff_version_major(), [xmlroff major version])
AC_DEFINE(XMLROFF_VERSION_MINOR, xmlroff_version_minor(), [xmlroff minor version])
AC_DEFINE(XMLROFF_VERSION_MICRO, xmlroff_version_micro(), [xmlroff micro version])

dnl libtool versioning
m4_define([lt_current],m4_eval(100 * xmlroff_version_minor + xmlroff_version_micro - xmlroff_interface_age))
m4_define([lt_revision],xmlroff_interface_age)
m4_define([lt_age],m4_eval(xmlroff_binary_age - xmlroff_interface_age))

AC_SUBST(LT_RELEASE,"xmlroff_version_major.xmlroff_version_minor")
AC_SUBST(LT_VERSION_INFO,"lt_current:lt_revision:lt_age")
AC_SUBST(LT_CURRENT_MINUS_AGE,m4_eval(lt_current - lt_age))

AC_CONFIG_SRCDIR(xmlroff.spec.in)
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE

AC_PROG_CC
AM_PROG_LIBTOOL

dnl
dnl Debug for TG (-Wunreachable-code)
dnl
AH_TEMPLATE([LIBFO_DEBUG],
            [Enable development debugging messages.])
AC_ARG_WITH(libfo_debug,
	    AC_HELP_STRING([--enable-libfo-debug],
                           [Enable development debugging messages (off)]))

if test "`pwd`" = "/usr/local/src/xslfo/xmlroff" ; then
    if test "${enable_libfo_debug}" = "" ; then
	enable_libfo_debug="yes"
    fi
dnl    CFLAGS="-Wall -g -O -ansi -pedantic -W -Wunused -Wimplicit -Wreturn-type -Wswitch -Wcomment -Wtrigraphs -Wformat -Wchar-subscripts -Wuninitialized -Wparentheses -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Winline "
    CFLAGS="-Wall -g -O -W "
    # Always build CUnit tests
    enable_cunit=yes
fi

if test "$enable_libfo_debug" = "yes" ; then
    echo Enabling development debug support
    LIBFO_DEBUG=1
    AC_DEFINE(LIBFO_DEBUG)
else    
    LIBFO_DEBUG=0
fi
AC_SUBST(LIBFO_DEBUG)

#
# Find pkg-config
# We need a minimum of version 0.5.
#
PKG_PROG_PKG_CONFIG([0.5])

#
# Checks for GLib
# We need a minimum of 2.12.0.
#
GLIB_REQUIRED_VERSION=2.12.0

have_glib=false
PKG_CHECK_MODULES(GLIB,
		  glib-2.0 >= $GLIB_REQUIRED_VERSION gobject-2.0 gmodule-2.0 gthread-2.0,
		  have_glib=true,
		  :)

if $have_glib ; then : ; else
      AC_MSG_ERROR([
*** Glib $GLIB_REQUIRED_VERSION or better is required. The latest version of
*** Glib is always available from ftp://ftp.gtk.org/.
  ])
fi

dnl **************************
dnl *** Checks for gtk-doc ***
dnl **************************

AC_ARG_WITH(html-dir,
	    AC_HELP_STRING([--with-html-dir=PATH],
			   [Path to installed docs]))

if test "x$with_html_dir" = "x" ; then
  HTML_DIR='${datadir}/gtk-doc/html'
else
  HTML_DIR=$with_html_dir
fi

AC_SUBST(HTML_DIR)


#
# Check for sufficiently new gtk-doc
#
GTK_DOC_MIN_VERSION=1.4

have_gtk_doc=false
PKG_CHECK_MODULES(GTK_DOC,
		  gtk-doc >= $GTK_DOC_MIN_VERSION,
		  have_gtk_doc=true,
		  :)
AC_MSG_RESULT($have_gtk_doc)

AM_CONDITIONAL(HAVE_GTK_DOC, $have_gtk_doc)
AC_SUBST(HAVE_GTK_DOC, $have_gtk_doc)

AC_CHECK_PROG(DB2HTML, db2html, true, false)
AM_CONDITIONAL(HAVE_DOCBOOK, $DB2HTML)

dnl Let people disable the gtk-doc stuff.
AC_ARG_ENABLE(gtk-doc,
              AC_HELP_STRING([--enable-gtk-doc],
                             [use gtk-doc to build documentation [default=no]]),
              enable_gtk_doc="$enableval",
              enable_gtk_doc=no)

if test "x$enable_gtk_doc" = "xyes" ; then
  if test "x$have_gtk_doc" = "xtrue" ; then
    enable_gtk_doc=yes
  else
    enable_gtk_doc=no 
  fi
fi

dnl NOTE: We need to use a separate automake conditional for this
dnl       to make this work with the tarballs.
AM_CONDITIONAL(ENABLE_GTK_DOC, test "x$enable_gtk_doc" = "xyes")

AC_ARG_ENABLE(man,
              [AC_HELP_STRING([--enable-man],
                              [regenerate man pages from Docbook [default=no]])],enable_man=yes,
              enable_man=no)

if test "${enable_man}" != no; then
dnl
dnl Check for xsltproc
dnl
AC_PATH_PROG([XSLTPROC], [xsltproc])
  if test -z "$XSLTPROC"; then
    enable_man=no
  fi
fi

AM_CONDITIONAL(ENABLE_MAN, test x$enable_man != xno)

#
# Checks for libxslt
#
# Variables for libxslt will also include values appropriate for
# libxml2.
#
LIBXSLT_PACKAGES=libxslt
LIBXSLT_REQUIRED_VERSION=1.0.3

have_libxslt=false

PKG_CHECK_MODULES(LIBXSLT,
		  $LIBXSLT_PACKAGES >= $LIBXSLT_REQUIRED_VERSION,
		  have_libxslt=true,
		  :)

if $have_libxslt ; then : ; else
      AC_MSG_ERROR([
*** Libxslt $LIBXSLT_REQUIRED_VERSION or newer is required.
*** Libxslt is available at http://xsltsoft.org/.
  ])
fi

AC_SUBST(LIBXSLT_LIBS)
AC_SUBST(LIBXSLT_CFLAGS)

AC_ARG_ENABLE(rebuilds,
	      AC_HELP_STRING([--disable-rebuilds],
                             [disable all source autogeneration rules]),
              ,
              enable_rebuilds=yes)

# define a MAINT-like variable REBUILD which is set if Perl
# is found, so autogenerated sources can be rebuilt

AC_CHECK_PROGS(PERL, perl5 perl)

REBUILD=\#
if test "x$enable_rebuilds" = "xyes" && \
     test -n "$PERL" && \
     $PERL -e 'exit !($] >= 5.002)' > /dev/null 2>&1 ; then
  REBUILD=
fi
AC_SUBST(REBUILD)

#
# Checks for FreeType
#
FREETYPE_LIBS=
FREETYPE_CFLAGS=
have_freetype=false
AC_PATH_PROG(FREETYPE_CONFIG, freetype-config, no)
if test "x$FREETYPE_CONFIG" != "xno" ; then
  FREETYPE_CFLAGS=`$FREETYPE_CONFIG --cflags`
  FREETYPE_LIBS=`$FREETYPE_CONFIG --libs`

  AC_CHECK_LIB(freetype, FT_New_Face, have_freetype=true
	       ,:,$FREETYPE_LIBS)
fi
AC_SUBST(FREETYPE_LIBS)
AC_SUBST(FREETYPE_CFLAGS)
AM_CONDITIONAL(HAVE_FREETYPE, $have_freetype) 

AH_TEMPLATE([ENABLE_GP],
	    [Enable support for GNOME Print backend of xmlroff.])

AC_ARG_ENABLE(gp,
	      AC_HELP_STRING([--enable-gp],
			     [build GNOME Print output capability (default=yes)]),
	      enable_gp_arg="$enableval",
              enable_gp_arg=yes)

if test "x$enable_gp_arg" != "xyes" ; then
  enable_gp_arg=no
fi

enable_gp=false
GNOMEPRINT_REQUIRES=""

if test "x$enable_gp_arg" = "xyes" ; then
  #
  # Check for libgnomeprint support requirement
  #
  have_gnomeprint=false

  PKG_CHECK_MODULES(GNOMEPRINT,
		    libgnomeprint-2.2 >= 2.8,
		    have_gnomeprint=true,
		    :)

  if $have_gnomeprint; then
    enable_gp=true

    AC_DEFINE(ENABLE_GP,1)
    GNOMEPRINT_REQUIRES="pango"
  else
    AC_DEFINE(ENABLE_GP,0)
    GNOMEPRINT_LIBS=""
    GNOMEPRINT_CFLAGS=""
  fi
fi

AC_SUBST(GNOMEPRINT_ENABLED, [$enable_gp])
AC_SUBST(GNOMEPRINT_REQUIRES)
AC_SUBST(GNOMEPRINT_LIBS)
AC_SUBST(GNOMEPRINT_CFLAGS)
AC_SUBST(ENABLE_GP, [$enable_gp])
AM_CONDITIONAL(ENABLE_GP, [$enable_gp])

#
# Checks for Cairo
#
AH_TEMPLATE([ENABLE_CAIRO],
	    [Enable support for Cairo backend of xmlroff.])

AC_ARG_ENABLE(cairo,
	      AC_HELP_STRING([--enable-cairo],
			     [build Cairo output capability (default=yes)]),
	      enable_cairo_arg="$enableval",
              enable_cairo_arg=yes)

if test "x$enable_cairo_arg" != "xyes" ; then
  enable_cairo_arg=no
fi

enable_cairo=false
CAIRO_REQUIRES=""

have_cairo=false
have_cairo_freetype=false
have_cairo_win32=false

if test "x$enable_cairo_arg" = "xyes" ; then
  PKG_CHECK_MODULES(CAIRO, cairo >= 1.2.4, have_cairo=true, :)
   
  if $have_cairo ; then
    pango_save_ldflags=$LDFLAGS
    m4_pattern_allow([PKG_CONFIG_DISABLE_UNINSTALLED])
    INSTALLED_CAIRO_LIBS=`PKG_CONFIG_DISABLE_UNINSTALLED=yes $PKG_CONFIG --libs cairo`
    LDFLAGS="$LDFLAGS $INSTALLED_CAIRO_LIBS"
    enable_cairo=true
    AC_CHECK_LIB(cairo, cairo_win32_scaled_font_select_font, have_cairo_win32=true, :)
    AC_DEFINE(ENABLE_CAIRO,1)
    if $have_cairo_win32 && $have_win32; then
      AC_DEFINE(HAVE_CAIRO_WIN32, 1, [Whether Cairo uses the Win32 GDI for fonts])
    else			  
      AC_CHECK_LIB(cairo, cairo_ft_scaled_font_lock_face, have_cairo_freetype=true, :)
      if $have_cairo_freetype && $have_freetype ; then
        AC_DEFINE(HAVE_CAIRO_FREETYPE, 1, [Whether Cairo uses FreeType for fonts])
      else
        have_cairo=false
	AC_DEFINE(ENABLE_CAIRO,0)
      fi
    fi
    LDFLAGS=$pango_save_ldflags
  fi
fi

AC_SUBST(CAIRO_ENABLED, [$enable_cairo])
AC_SUBST(ENABLE_CAIRO, [$enable_cairo])
AM_CONDITIONAL(ENABLE_CAIRO, [$enable_cairo])
AM_CONDITIONAL(HAVE_CAIRO, $have_cairo)
AM_CONDITIONAL(HAVE_CAIRO_WIN32, $have_cairo_win32 && $have_win32)
AM_CONDITIONAL(HAVE_CAIRO_FREETYPE, $have_cairo_freetype && $have_freetype)

AH_TEMPLATE(HAVE_LIBRSVG,
	    [Whether Cairo can render SVG files])
have_librsvg=false
if $enable_cairo ; then
    PKG_CHECK_MODULES(LIBRSVG,
          librsvg-2.0 >= 2.4.0,
		  have_librsvg=true,
	  :)
fi
AM_CONDITIONAL(HAVE_LIBRSVG, $have_librsvg)
AC_SUBST(HAVE_LIBRSVG, [$have_librsvg])
AC_SUBST(LIBRSVG_LIBS)
AC_SUBST(LIBRSVG_CFLAGS)

#
# Check have at least one backend enabled
#
if $enable_gp || $enable_cairo ; then : ; else
  AC_MSG_ERROR([
*** No backends are enabled.
*** Must have at least one backend to build xmlroff.])
fi

#
# Checks for Pango
#
PANGO_PACKAGES=
PANGO_REQUIRED_VERSION=1.16

if $enable_gp ; then
   PANGO_PACKAGES="$GNOMEPRINT_REQUIRES"
fi
if $enable_cairo ; then
   PANGO_PACKAGES="$PANGO_PACKAGES pangocairo"
fi
have_pango=false

PKG_CHECK_MODULES(PANGO,
		  $PANGO_PACKAGES >= $PANGO_REQUIRED_VERSION,
		  have_pango=true,
		  :)

if $have_pango ; then : ; else
      AC_MSG_ERROR([
*** Pango $PANGO_REQUIRED_VERSION or newer is required.
*** Pango is available at http://pango.org/.
  ])
fi

AC_SUBST(PANGO_LIBS)
AC_SUBST(PANGO_CFLAGS)

#
# Checks for GdkPixBuf
#
GDKPIXBUF_PACKAGES=gdk-pixbuf-2.0
GDKPIXBUF_REQUIRED_VERSION=2.2

have_gdkpixbuf=false

PKG_CHECK_MODULES(GDKPIXBUF,
		  $GDKPIXBUF_PACKAGES >= $GDKPIXBUF_REQUIRED_VERSION,
		  have_gdkpixbuf=true,
		  :)

if $have_gdkpixbuf ; then : ; else
      AC_MSG_ERROR([
*** GdkPixbuf $GDKPIXBUF_REQUIRED_VERSION or newer is required.
*** GdkPixbuf is available at http://gtk.org.
  ])
fi

AC_SUBST(GDKPIXBUF_LIBS)
AC_SUBST(GDKPIXBUF_CFLAGS)

AC_MSG_CHECKING([for some Win32 platform])
case "$host" in
  *-*-mingw*|*-*-cygwin*)
    xmlroff_platform_win32=yes
    ;;
  *)
    xmlroff_platform_win32=no
    ;;
esac
AC_MSG_RESULT([$xmlroff_platform_win32])
AM_CONDITIONAL(PLATFORM_WIN32, test "$xmlroff_platform_win32" = "yes")

AH_TEMPLATE([PIXELS_PER_INCH],
	    [Pixels per inch for use with graphics without intrinsic size.])

pixels_per_inch_default=96

AC_ARG_WITH(pixels_per_inch,
	      AC_HELP_STRING([--with-pixels-per-inch],
			     [Pixels per inch (default=96)]),
	      pixels_per_inch="$withval", :)

if test "x$with_pixels_per_inch" = "x" ; then
  PIXELS_PER_INCH=$pixels_per_inch_default
else
  PIXELS_PER_INCH=$with_pixels_per_inch
fi

AC_DEFINE_UNQUOTED(PIXELS_PER_INCH,$PIXELS_PER_INCH)

AH_TEMPLATE([ENABLE_CLIP],
            [Enable clipping to area extent.  Clipping should only be disabled when debugging.])
AC_ARG_ENABLE(clip,
	      AC_HELP_STRING([--enable-clip],
			     [enable clipping to area extent (default=yes)]),
	      enable_clip_arg="$clipval", enable_clip_arg=yes)

if test "x$enable_clip_arg" = "xyes" ; then
  AC_DEFINE(ENABLE_CLIP,1)
else
    AC_DEFINE(ENABLE_CLIP,0)
fi

dnl
dnl Check for svn2cl for generating ChangeLog
dnl
enable_svn2cl=yes
AC_PATH_PROG([SVN2CL], [svn2cl])
if test -z "$SVN2CL"; then
  enable_svn2cl=no
fi

AM_CONDITIONAL(ENABLE_SVN2CL, test x$enable_svn2cl != xno)

AC_ARG_WITH(changelog-oldest,
	    AC_HELP_STRING([--with-changelog-oldest=NUMBER],
			   [Oldest revision to include in ChangeLog]))

if test "x$with_changelog_oldest" = "x" ; then
  # Update this when moving current ChangeLog to ChangeLog.pre-nn.
  CHANGELOG_OLDEST=377
else
  CHANGELOG_OLDEST=$with_changelog_oldest
fi

AC_SUBST(CHANGELOG_OLDEST)

#
# Check for CUnit
#
OLD_CFLAGS="$CFLAGS"
CUNIT_CFLAGS="-I/usr/local/include"
CFLAGS="$CFLAGS $CUNIT_CFLAGS"
OLD_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS -I/usr/local/include"
OLD_LIBS="$LIBS"
CUNIT_LIBS="-L/usr/local/lib"
LIBS="$LIBS $CUNIT_LIBS"

have_cunit=false
AC_CHECK_HEADER([CUnit/CUnit.h],
		 have_cunit=true)

dnl Let people disable the CUnit stuff.
AC_ARG_ENABLE(cunit,
	      AC_HELP_STRING([--enable-cunit],
                             [use CUnit to run unit tests (default=no)]),
              enable_cunit_arg="$enableval",
              enable_cunit_arg=no)

if test "x$enable_cunit_arg" != "xno" ; then
  enable_cunit_arg=yes
fi

build_cunit=false
if test "x$enable_cunit_arg" = "xyes" && \
    test "x$have_cunit" = "xtrue" ; then
  build_cunit=true
fi
CUNIT_LIBS="$CUNIT_LIBS -lcunit"
AC_SUBST(CUNIT_LIBS)
AC_SUBST(CUNIT_CFLAGS)
CFLAGS="$OLD_CFLAGS"
CPPFLAGS="$OLD_CPPFLAGS"
LIBS="$OLD_LIBS"

dnl NOTE: We need to use a separate automake conditional for this
dnl       to make this work with the tarballs.
AM_CONDITIONAL(ENABLE_CUNIT,$build_cunit)

AC_CONFIG_COMMANDS([libfo/libfo-features.h],
          [featuresfile=libfo/libfo-features.h
           outfile=$featuresfile.tmp
           AC_MSG_NOTICE([creating $featuresfile])
           cat >$outfile <<_EOF
/* Generated by configure. Do not edit */
#ifndef __LIBFO_FEATURES_H__
#define __LIBFO_FEATURES_H__

#define LIBFO_VERSION_MAJOR $LIBFO_VERSION_MAJOR
#define LIBFO_VERSION_MINOR $LIBFO_VERSION_MINOR
#define LIBFO_VERSION_MICRO $LIBFO_VERSION_MICRO
#define LIBFO_PIXELS_PER_INCH $LIBFO_PIXELS_PER_INCH

#define LIBFO_VERSION_STRING "$LIBFO_VERSION_MAJOR.$LIBFO_VERSION_MINOR.$LIBFO_VERSION_MICRO"
#define LIBFO_VERSION_EXTRA "$LIBFO_VERSION_EXTRA"

_EOF
	# TODO: define macros for enabled features/backends here

        echo '' >>$outfile
        echo '#endif /*  __LIBFO_FEATURES_H__ */' >>$outfile

        if cmp -s $outfile $featuresfile; then
          AC_MSG_NOTICE([$featuresfile is unchanged])
          rm -f $outfile
        else
          mv $outfile $featuresfile
        fi
],[
        LIBFO_VERSION_MAJOR=$XMLROFF_VERSION_MAJOR
        LIBFO_VERSION_MINOR=$XMLROFF_VERSION_MINOR
        LIBFO_VERSION_MICRO=$XMLROFF_VERSION_MICRO
        LIBFO_VERSION_EXTRA=$XMLROFF_VERSION_EXTRA
	LIBFO_PIXELS_PER_INCH=$PIXELS_PER_INCH
])

AC_OUTPUT([
INSTALL
Makefile 
cunit/Makefile
docs/Makefile
examples/Makefile
examples/xml2003/Makefile
libfo/Makefile
libfo/area/Makefile
libfo/datatype/Makefile
libfo/expr/Makefile
libfo/fo/Makefile
libfo/property/Makefile
libfo/util/Makefile
libfo-0.6.pc
xmlroff.spec
xmlroff/Makefile
catalog.xml
])

fo_doc_subtypes=""
if $enable_cairo  ; then fo_doc_subtypes="$fo_doc_subtypes 'Cairo'"; fi
if $enable_gp     ; then fo_doc_subtypes="$fo_doc_subtypes 'GNOME Print'"; fi

echo "
Configuration:
  Enabled FoDoc subtypes:$fo_doc_subtypes"

echo "  CUnit tests enabled:    $build_cunit"

