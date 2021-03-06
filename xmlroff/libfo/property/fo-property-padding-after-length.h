/* Fo
 * fo-property-padding-after-length.h: 'padding-after-length' property
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007-2008 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_PROPERTY_PADDING_AFTER_LENGTH_H__
#define __FO_PROPERTY_PADDING_AFTER_LENGTH_H__

#include <libfo/fo-utils.h>
#include <libfo/property/fo-property.h>

G_BEGIN_DECLS

/* padding-after-length */
/* Inherited: FALSE */
/* Shorthand: FALSE */
/* <padding-width> | <length-conditional> | inherit */
/* Initial value: 0pt */

#define FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH              (fo_property_padding_after_length_get_type ())
#define FO_PROPERTY_PADDING_AFTER_LENGTH(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH, FoPropertyPaddingAfterLength))
#define FO_PROPERTY_PADDING_AFTER_LENGTH_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH, FoPropertyPaddingAfterLengthClass))
#define FO_IS_PROPERTY_PADDING_AFTER_LENGTH(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH))
#define FO_IS_PROPERTY_PADDING_AFTER_LENGTH_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH))
#define FO_PROPERTY_PADDING_AFTER_LENGTH_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_PROPERTY_PADDING_AFTER_LENGTH, FoPropertyPaddingAfterLengthClass))


typedef struct _FoPropertyPaddingAfterLength      FoPropertyPaddingAfterLength;
typedef struct _FoPropertyPaddingAfterLengthClass FoPropertyPaddingAfterLengthClass;

GType        fo_property_padding_after_length_get_type    (void) G_GNUC_CONST;
FoProperty * fo_property_padding_after_length_new         (void);
FoProperty * fo_property_padding_after_length_get_initial (void);

G_END_DECLS

#endif /* !__FO_PROPERTY_PADDING_AFTER_LENGTH_H__ */
