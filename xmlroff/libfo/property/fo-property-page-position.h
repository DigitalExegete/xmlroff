/* Fo
 * fo-property-page-position.h: 'page-position' property
 *
 * Copyright (C) 2001-2006 Sun Microsystems
 * Copyright (C) 2007-2010 Menteith Consulting Ltd
 * Copyright (C) 2011 Mentea
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_PROPERTY_PAGE_POSITION_H__
#define __FO_PROPERTY_PAGE_POSITION_H__

#include <libfo/fo-utils.h>
#include <libfo/property/fo-property.h>

G_BEGIN_DECLS

/* page-position */
/* Inherited: FALSE */
/* Shorthand: FALSE */
/* first | last | rest | any | inherit */
/* Initial value: any */

#define FO_TYPE_PROPERTY_PAGE_POSITION              (fo_property_page_position_get_type ())
#define FO_PROPERTY_PAGE_POSITION(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_PROPERTY_PAGE_POSITION, FoPropertyPagePosition))
#define FO_PROPERTY_PAGE_POSITION_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_PROPERTY_PAGE_POSITION, FoPropertyPagePositionClass))
#define FO_IS_PROPERTY_PAGE_POSITION(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_PROPERTY_PAGE_POSITION))
#define FO_IS_PROPERTY_PAGE_POSITION_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_PROPERTY_PAGE_POSITION))
#define FO_PROPERTY_PAGE_POSITION_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_PROPERTY_PAGE_POSITION, FoPropertyPagePositionClass))


/**
 * FoPropertyPagePosition:
 *
 * Instance of the 'page-position' property.
 **/
typedef struct _FoPropertyPagePosition      FoPropertyPagePosition;

/**
 * FoPropertyPagePositionClass:
 *
 * Class structure for the 'page-position' property.
 **/
typedef struct _FoPropertyPagePositionClass FoPropertyPagePositionClass;

GType        fo_property_page_position_get_type    (void) G_GNUC_CONST;
FoProperty * fo_property_page_position_new         (void);
FoProperty * fo_property_page_position_get_initial (void);

G_END_DECLS

#endif /* !__FO_PROPERTY_PAGE_POSITION_H__ */
