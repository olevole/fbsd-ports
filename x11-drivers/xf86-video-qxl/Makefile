# $FreeBSD: $

PORTNAME=	xf86-video-qxl
PORTVERSION=	0.1.5
CATEGORIES=	x11-drivers

MAINTAINER=	olevole@olevole.ru
COMMENT=	X.Org X server -- QXL display driver

XORG_CAT=	driver

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol

USE_LDCONFIG=	yes
USE_XORG=	pciaccess pixman x11 xcb xext xrender xv xvmc

USES+=		cpe autoreconf pkgconfig

# we can't use pathfix with USES=autoreconf
MAKE_ARGS=	pkgconfigdir="$(PREFIX)/libdata/pkgconfig"

CONFIGURE_ARGS+=	--enable-xspice

.include <bsd.port.mk>
