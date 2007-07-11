/* Fo
 * fo-page-sequence-area.h: Generate area for page-sequence formatting object
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#include <libfo/fo-utils.h>
#include <libfo/fo-doc.h>
#include <libfo/fo/fo-fo.h>
#include <libfo/area/fo-area.h>

#ifndef __FO_PAGE_SEQUENCE_AREA_H__
#define __FO_PAGE_SEQUENCE_AREA_H__

G_BEGIN_DECLS

void fo_page_sequence_area_new (FoFo    *fo_node,
				FoDoc   *fo_doc,
				FoArea  *parent_area,
				FoArea **new_area,
				guint    debug_level);
void fo_page_sequence_area_new2 (FoFo                *fo_node,
				 FoFoAreaNew2Context *context,
				 GError             **error);

G_END_DECLS

#endif /* !__FO_PAGE_SEQUENCE_AREA_H__ */