# Created by: olevole@olevole.ru
# $FreeBSD:$
PORTNAME=	spice-gtk
PORTVERSION=	0.26
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	olevole@olevole.ru
COMMENT=	spice-gtk is a GTK+2 and GTK+3 SPICE widge

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2

#CONFIGURE_ENV=	SSL_CFLAGS="-I${OPENSSLINC}" \
#		SSL_LIBS="-L${OPENSSLLIB}"

USE_XORG=	pixman
USE_GNOME=	gnomeprefix gtk20 gtk30 intltool introspection
USES=		gmake libtool pkgconfig python tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-audio=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
