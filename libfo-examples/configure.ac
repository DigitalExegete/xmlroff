dnl Process this file with autoconf to create configure.
set
# require autoconf 2.53
AC_PREREQ(2.53)

AC_INIT([xmlroff XSL Formatter libfo library usage examples],
	0.3.0,
	[http://sourceforge.net/tracker/?group_id=73148],
	libfo-examples)
AC_CONFIG_SRCDIR([xmlroff-init2.c])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AM_PROG_LIBTOOL
AC_PROG_INSTALL

# Checks for libraries.

PKG_CHECK_MODULES(LIBFO,
		  libfo-0.3 >= 0.3.0,
		  have_libfo=true,
		  have_libfo=false)


AH_TEMPLATE([ENABLE_GP],
	    [Enable support for GNOME Print backend of xmlroff.])

if $have_libfo ; then
  AC_MSG_CHECKING(['GNOME Print' backend enabled])
  enable_gp=`pkg-config --variable=enable_gp libfo-0.3`

  if test x"$enable_gp" = xtrue ; then
    AC_DEFINE(ENABLE_GP,1)
    AC_MSG_RESULT(yes)
  else
    AC_DEFINE(ENABLE_GP,0)
    AC_MSG_RESULT(NO)
  fi
fi

AC_SUBST(LIBFO_LIBS)
AC_SUBST(LIBFO_CFLAGS)

PKG_CHECK_MODULES(GTK,
		  gtk+-2.0 >= 2.2,
		  have_gtk=true,
		  have_gtk=false)

AC_SUBST(GTK_LIBS)
AC_SUBST(GTK_CFLAGS)

PKG_CHECK_MODULES(GMODULE,
		  gmodule-2.0 >= 2.2,
		  have_gmodule=true,
		  have_gmodule=false)

AC_SUBST(GMODULE_LIBS)
AC_SUBST(GMODULE_CFLAGS)

AC_ARG_WITH(popt, [  --with-popt=DIR    Location where Popt is installed],,with_popt=yes)

POPT_LIBS="-lpopt"
AC_MSG_CHECKING(for popt location)
  
if test "x$with_popt" = xyes ; then         
# Search for Popt in a common location.
AC_CHECK_HEADERS(popt.h)
else
   if test "x$with_popt" != xno ; then
      if test -x $with_popt/lib/libpopt.so ; then
	 POPT_CFLAGS="-I$with_popt/include"
         POPT_LIBS="-R $with_popt/lib -lpopt"
      fi
   fi
fi

if test "x$POPT_LIBS" = x ; then
  AC_MSG_RESULT(none)
else
  AC_MSG_RESULT($POPT_LIBS)
fi

AC_SUBST(POPT_CFLAGS)
AC_SUBST(POPT_LIBS)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT