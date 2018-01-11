# $FreeBSD: $

PORTNAME=	xf86-video-qxl
PORTVERSION=	0.1.5
CATEGORIES=	x11-drivers

MAINTAINER=	olevole@olevole.ru
COMMENT=	X.Org X server -- QXL display driver

XORG_CAT=	driver

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		libspice-server>=0.14.0:devel/libspice-server \
		${LOCALBASE}/include/linux/input.h:multimedia/v4l_compat
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		libspice-server>=0.14.0:devel/libspice-server \

USES+=		localbase:ldflags pkgconfig python:2.7 shebangfix ssl

SPICE_CFLAGS+=	-I${OPENSSLINC} -I${PREFIX}/include/spice-server
SPICE_LIBS+=	-L${OPENSSLLIB} -lcrypto -lssl -lspice-server

CONFIGURE_ENV+=	SPICE_CFLAGS="${SPICE_CFLAGS}" SPICE_LIBS="${SPICE_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_CFLAGS}" OPENSSL_LIBS="${SPICE_LIBS}"

CONFIGURE_ARGS+=--enable-xspice

python_OLD_CMD=	"/usr/bin/python"
SHEBANG_FILES=	scripts/Xspice

.include <bsd.port.mk>
