/* -*- Mode: C; c-basic-offset: 3 -*-
    Copyright (C) 2002-2005  Thomas Ries <tries@gmx.net>

    This file is part of Siproxd.
    
    Siproxd is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    Siproxd is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with Siproxd; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
*/

#include <osipparser2/osip_parser.h>

static char const ident[]="$Id$";

/*
 * This file contains wrapper functions to call the osip2_ library.
 * depending on the used version of libosip2, the calling arguments
 * differ. E.g. Libosip2-2.2.0 (against 2.0.9) introduces a "size"
 * argument for a number of functions used by siproxd.
 */

int sip_message_parse(osip_message_t * sip, const char *buf) {
#ifdef HAVE_FUNC_OSIP_MESSAGE_PARSE_3
   return osip_message_parse(sip, buf, strlen(buf));
#else 
   return osip_message_parse(sip, buf);
#endif
}

int sip_message_to_str(osip_message_t * sip, char **dest) {
#ifdef  HAVE_FUNC_OSIP_MESSAGE_TO_STR_3
   size_t len;
   return osip_message_to_str(sip, dest, &len);
#else 
   return osip_message_to_str(sip, dest);
#endif
}

int sip_body_to_str(const osip_body_t * body, char **dest) {
#ifdef  HAVE_FUNC_OSIP_BODY_TO_STR_3
   size_t len;
   return osip_body_to_str (body, dest, &len);
#else 
   return osip_body_to_str(body, &dest);
#endif
}

int sip_message_set_body(osip_message_t * sip, const char *buf) {
#ifdef  HAVE_FUNC_OSIP_MESSAGE_SET_BODY_3
   return osip_message_set_body(sip, buf, strlen(buf));
#else 
   return osip_message_set_body(sip, buf);
#endif
}

