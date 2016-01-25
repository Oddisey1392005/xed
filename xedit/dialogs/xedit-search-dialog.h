/*
 * xedit-search-dialog.h
 * This file is part of xedit
 *
 * Copyright (C) 2005 Paolo Maggi
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA 02110-1301, USA.
 */
 
/*
 * Modified by the xedit Team, 2005. See the AUTHORS file for a 
 * list of people on the xedit Team.  
 * See the ChangeLog files for a list of changes. 
 *
 * $Id$
 */

#ifndef __XEDIT_SEARCH_DIALOG_H__
#define __XEDIT_SEARCH_DIALOG_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

/*
 * Type checking and casting macros
 */
#define XEDIT_TYPE_SEARCH_DIALOG              (xedit_search_dialog_get_type())
#define XEDIT_SEARCH_DIALOG(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), XEDIT_TYPE_SEARCH_DIALOG, XeditSearchDialog))
#define XEDIT_SEARCH_DIALOG_CONST(obj)        (G_TYPE_CHECK_INSTANCE_CAST((obj), XEDIT_TYPE_SEARCH_DIALOG, XeditSearchDialog const))
#define XEDIT_SEARCH_DIALOG_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass), XEDIT_TYPE_SEARCH_DIALOG, XeditSearchDialogClass))
#define XEDIT_IS_SEARCH_DIALOG(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj), XEDIT_TYPE_SEARCH_DIALOG))
#define XEDIT_IS_SEARCH_DIALOG_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), XEDIT_TYPE_SEARCH_DIALOG))
#define XEDIT_SEARCH_DIALOG_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj), XEDIT_TYPE_SEARCH_DIALOG, XeditSearchDialogClass))

/* Private structure type */
typedef struct _XeditSearchDialogPrivate XeditSearchDialogPrivate;

/*
 * Main object structure
 */
typedef struct _XeditSearchDialog XeditSearchDialog;

struct _XeditSearchDialog 
{
	GtkDialog dialog;

	/*< private > */
	XeditSearchDialogPrivate *priv;
};

/*
 * Class definition
 */
typedef struct _XeditSearchDialogClass XeditSearchDialogClass;

struct _XeditSearchDialogClass 
{
	GtkDialogClass parent_class;
	
	/* Key bindings */
	gboolean (* show_replace) (XeditSearchDialog *dlg);
};

enum
{
	XEDIT_SEARCH_DIALOG_FIND_RESPONSE = 100,
	XEDIT_SEARCH_DIALOG_REPLACE_RESPONSE,
	XEDIT_SEARCH_DIALOG_REPLACE_ALL_RESPONSE
};

/*
 * Public methods
 */
GType 		 xedit_search_dialog_get_type 		(void) G_GNUC_CONST;

GtkWidget	*xedit_search_dialog_new		(GtkWindow         *parent,
							 gboolean           show_replace);

void		 xedit_search_dialog_present_with_time	(XeditSearchDialog *dialog,
							 guint32 timestamp);

gboolean	 xedit_search_dialog_get_show_replace	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_show_replace	(XeditSearchDialog *dialog,
							 gboolean           show_replace);


void		 xedit_search_dialog_set_search_text	(XeditSearchDialog *dialog,
							 const gchar       *text);
const gchar	*xedit_search_dialog_get_search_text	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_replace_text	(XeditSearchDialog *dialog,
							 const gchar       *text);
const gchar	*xedit_search_dialog_get_replace_text	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_match_case	(XeditSearchDialog *dialog,
							 gboolean           match_case);
gboolean	 xedit_search_dialog_get_match_case	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_entire_word	(XeditSearchDialog *dialog,
							 gboolean           entire_word);
gboolean	 xedit_search_dialog_get_entire_word	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_backwards	(XeditSearchDialog *dialog,
							 gboolean           backwards);
gboolean	 xedit_search_dialog_get_backwards	(XeditSearchDialog *dialog);

void		 xedit_search_dialog_set_wrap_around	(XeditSearchDialog *dialog,
							 gboolean           wrap_around);
gboolean	 xedit_search_dialog_get_wrap_around	(XeditSearchDialog *dialog);
   

void		xedit_search_dialog_set_parse_escapes (XeditSearchDialog *dialog,
                                    		       gboolean           parse_escapes);
gboolean	xedit_search_dialog_get_parse_escapes (XeditSearchDialog *dialog);

G_END_DECLS

#endif  /* __XEDIT_SEARCH_DIALOG_H__  */
