# libfo and xmlroff Makefile.am

# Only building CUnit tests when both have CUnit and tests are
# enabled.
if ENABLE_CUNIT
CUNIT_DIRS = cunit
endif

SUBDIRS = libfo xmlroff . examples docs $(CUNIT_DIRS)

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

INCLUDES = \
	-DG_LOG_DOMAIN=\"libfo\"	\
	$(LIBXSLT_CFLAGS)	\
	$(GLIB_CFLAGS)		\
	-Ilibfo


pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libfo-0.6.pc

xmldir = $(datadir)/xml/libfo-@VERSION@
xml_DATA = \
	catalog.xml		\
	libfo-compat.xsl

EXTRA_DIST = \
	catalog.xml.in		\
	libfo-compat.xsl	\
	xmlroff.fo		\
	xmlroff.spec		\
	xmlroff.spec.in		\
	tools/insert-file-as-string.pl

FORCE:

ChangeLog:	FORCE
if ENABLE_SVN2CL
	svn2cl --include-actions --authors=AUTHORS --group-by-day --separate-daylogs --include-rev --ignore-message-starting='#' --revision HEAD:$(CHANGELOG_OLDEST)
endif

srpm:
	rpmbuild -ts --nodeps $(PACKAGE)-$(VERSION).tar.gz

svn-tag:
	-svn mkdir -m"Tagging for modules of xmlroff $(VERSION)." svn://svn.xmlroff.org/tags/xmlroff-$(VERSION)
	-svn cp -m"Tagging xmlroff $(VERSION)." svn://svn.xmlroff.org/trunk/xmlroff svn://svn.xmlroff.org/tags/xmlroff-$(VERSION)/xmlroff
