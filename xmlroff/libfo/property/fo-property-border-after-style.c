/* Fo
 * fo-property-border-after-style.c: 'border-after-style' property
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * See COPYING! for the status of this software.
 */

#include <string.h>
#include "fo-utils.h"
#include "fo-context.h"
#include "datatype/fo-datatype.h"
#include "property/fo-property-private.h"
#include "property/fo-property-font-size.h"
#include "property/fo-property-border-after-style.h"
#include "property/fo-property-util.h"

/* border-after-style */
/* Inherited: FALSE */
/* Shorthand: FALSE */
/* <border-style> | inherit */
/* Initial value: none */

struct _FoPropertyBorderAfterStyle
{
  FoProperty parent_instance;
};

struct _FoPropertyBorderAfterStyleClass
{
  FoPropertyClass parent_class;
};

static void fo_property_border_after_style_init         (FoPropertyBorderAfterStyle      *property_border_after_style);
static void fo_property_border_after_style_class_init   (FoPropertyBorderAfterStyleClass *klass);
static void fo_property_border_after_style_finalize     (GObject       *object);

static const gchar class_name[] = "border-after-style";
static gpointer parent_class;

/**
 * fo_property_border_after_style_get_type:
 * 
 * Register the #FoPropertyBorderAfterStyle type if not already registered and
 * return its #GType value.
 * 
 * Return value: #GType of #FoPropertyBorderAfterStyle.
 **/
GType
fo_property_border_after_style_get_type (void)
{
  static GType object_type = 0;

  if (!object_type)
    {
      static const GTypeInfo object_info =
      {
        sizeof (FoPropertyBorderAfterStyleClass),
        NULL,           /* base_init */
        NULL,           /* base_finalize */
        (GClassInitFunc) fo_property_border_after_style_class_init,
        NULL,           /* class_finalize */
        NULL,           /* class_data */
        sizeof (FoPropertyBorderAfterStyle),
        0,              /* n_preallocs */
        (GInstanceInitFunc) fo_property_border_after_style_init,
	NULL		/* value_table */
      };

      object_type = g_type_register_static (FO_TYPE_PROPERTY,
                                            class_name,
                                            &object_info, 0);
    }

  return object_type;
}

/**
 * fo_property_border_after_style_init:
 * @border_after_style: #FoPropertyBorderAfterStyle object to initialise.
 * 
 * Implements #GInstanceInitFunc for #FoPropertyBorderAfterStyle.
 **/
void
fo_property_border_after_style_init (FoPropertyBorderAfterStyle *border_after_style)
{
  FO_PROPERTY (border_after_style)->value =
    g_object_ref (fo_property_util_get_style_initial ());
}

/**
 * fo_property_border_after_style_class_init:
 * @klass: #FoPropertyBorderAfterStyleClass object to initialise.
 * 
 * Implements #GClassInitFunc for #FoPropertyBorderAfterStyleClass.
 **/
void
fo_property_border_after_style_class_init (FoPropertyBorderAfterStyleClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  FoPropertyClass *property_class = FO_PROPERTY_CLASS (klass);

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = fo_property_border_after_style_finalize;

  property_class->is_inherited = FALSE;
  property_class->is_shorthand = FALSE;
  property_class->resolve_enum =
    fo_property_util_resolve_style_enum;
  property_class->validate =
    fo_property_util_validate_style;
  property_class->get_initial =
    fo_property_border_after_style_get_initial;
}

/**
 * fo_property_border_after_style_finalize:
 * @object: #FoPropertyBorderAfterStyle object to finalize.
 * 
 * Implements #GObjectFinalizeFunc for #FoPropertyBorderAfterStyle.
 **/
void
fo_property_border_after_style_finalize (GObject *object)
{
  FoPropertyBorderAfterStyle *border_after_style;

  border_after_style = FO_PROPERTY_BORDER_AFTER_STYLE (object);

  G_OBJECT_CLASS (parent_class)->finalize (object);
}


/**
 * fo_property_border_after_style_new:
 * 
 * Creates a new #FoPropertyBorderAfterStyle initialized to default value.
 * 
 * Return value: the new #FoPropertyBorderAfterStyle.
 **/
FoProperty*
fo_property_border_after_style_new (void)
{
  FoProperty* border_after_style;

  border_after_style =
    FO_PROPERTY (g_object_new (fo_property_border_after_style_get_type (),
                               NULL));

  return border_after_style;
}

/**
 * fo_property_border_after_style_get_initial:
 * 
 * Get an instance of the property with the correct initial value.
 * 
 * Return value: An instance of the property.
 **/
FoProperty*
fo_property_border_after_style_get_initial (void)
{
  static FoProperty *border_after_style = NULL;

  if (border_after_style == NULL)
    {
      border_after_style =
	fo_property_border_after_style_new ();
    }

  return border_after_style;
}
