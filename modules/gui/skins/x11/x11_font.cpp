/*****************************************************************************
 * x11_font.cpp: X11 implementation of the Font class
 *****************************************************************************
 * Copyright (C) 2003 VideoLAN
 * $Id: x11_font.cpp,v 1.1 2003/04/28 14:32:57 asmax Exp $
 *
 * Authors: Cyril Deguet     <asmax@videolan.org>
 *          Emmanuel Puig    <karibu@via.ecp.fr>
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111,
 * USA.
 *****************************************************************************/

#ifdef X11_SKINS

//--- X11 -----------------------------------------------------------------
#include <X11/Xlib.h>

//--- VLC -------------------------------------------------------------------
#include <vlc/intf.h>

//--- SKIN ------------------------------------------------------------------
#include "../src/graphics.h"
#include "../os_graphics.h"
#include "../src/font.h"
#include "../os_font.h"



//---------------------------------------------------------------------------
// Font object
//---------------------------------------------------------------------------
X11Font::X11Font( intf_thread_t *_p_intf, string fontname, int size,
    int color, int weight, bool italic, bool underline )
    : SkinFont( _p_intf, fontname, size, color, weight, italic, underline )
{
/*    Context = gdk_pango_context_get();
    Layout = pango_layout_new( Context );

    // Text properties setting
    FontDesc    = pango_font_description_new();

    pango_font_description_set_family( FontDesc, fontname.c_str() );

    pango_font_description_set_size( FontDesc, size * PANGO_SCALE );

    if( italic )
    {
        pango_font_description_set_style( FontDesc, PANGO_STYLE_ITALIC );
    }
    else
    {
        pango_font_description_set_style( FontDesc, PANGO_STYLE_NORMAL );
    }

    pango_font_description_set_weight( FontDesc, (PangoWeight)weight );

    //pango_context_set_font_description( Context, FontDesc );
    pango_layout_set_font_description( Layout, FontDesc );

    // Set attributes
    PangoAttrList *attrs = pango_attr_list_new();
    // FIXME: doesn't work 
    if( underline )
    {
        pango_attr_list_insert( attrs, 
            pango_attr_underline_new( PANGO_UNDERLINE_SINGLE ) );
    }
    pango_layout_set_attributes( Layout, attrs );*/
}
//---------------------------------------------------------------------------
X11Font::~X11Font()
{
}
//---------------------------------------------------------------------------
void X11Font::AssignFont( Graphics *dest )
{
}
//---------------------------------------------------------------------------
void X11Font::GetSize( string text, int &w, int &h )
{
/*    pango_layout_set_text( Layout, text.c_str(), text.length() );
    pango_layout_get_pixel_size( Layout, &w, &h );*/
}
//---------------------------------------------------------------------------
void X11Font::GenericPrint( Graphics *dest, string text, int x, int y,
                                 int w, int h, int align, int color )
{
/*    // Set text
    pango_layout_set_text( Layout, text.c_str(), -1 );

    // Set size
    pango_layout_set_width( Layout, -1 );
    int real_w, real_h;

    // Create buffer image
    Graphics* cov = (Graphics *)new OSGraphics( w, h );
    cov->CopyFrom( 0, 0, w, h, dest, x, y, SRC_COPY );

    // Get handles
    GdkDrawable *drawable = ( (X11Graphics *)cov )->GetImage();
    GdkGC *gc = ( (X11Graphics *)cov )->GetGC();

    // Set width of text
    pango_layout_set_width( Layout, w * PANGO_SCALE );

    // Set attributes
    pango_layout_set_alignment( Layout, (PangoAlignment)align );
    
    // Avoid trans�rency for black text
    if( color == 0 ) color = 10;
    gdk_rgb_gc_set_foreground( gc, color );

    // Render text on buffer
    gdk_draw_layout( drawable, gc, 0, 0, Layout );

    // Copy buffer on dest graphics
    dest->CopyFrom( x, y, w, h, cov, 0, 0, SRC_COPY );

    // Free memory
    delete (OSGraphics *)cov;*/
}

//---------------------------------------------------------------------------
void X11Font::Print( Graphics *dest, string text, int x, int y, int w,
                       int h, int align )
{
    GenericPrint( dest, text, x, y, w, h, align, Color );
}
//---------------------------------------------------------------------------
void X11Font::PrintColor( Graphics *dest, string text, int x, int y, int w,
                            int h, int align, int color )
{
    GenericPrint( dest, text, x, y, w, h, align, color );
}
//---------------------------------------------------------------------------

#endif
