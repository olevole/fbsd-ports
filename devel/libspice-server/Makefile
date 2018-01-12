# Created by: olevole@olevole.ru
# $FreeBSD: $

PORTNAME=	libspice-server
PORTVERSION=	0.14.0
CATEGORIES=	devel
MASTER_SITES=	https://www.spice-space.org/download/releases/
DISTNAME=	spice-${PORTVERSION}

MAINTAINER=	olevole@olevole.ru
COMMENT=	Implements the server side of the SPICE protocol

LICENSE=	GPLv2

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol

USES=		autoreconf gmake jpeg libtool localbase:ldflag pkgconfig \
		ssl tar:bzip2

USE_GNOME=	glib20
USE_XORG=	pixman

CPE_VENDOR=	redhat

CONFIGURE_ARGS+=--disable-celt051

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=	-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=	SSL_CFLAGS="${SPICE_SSL_CFLAGS}" SSL_LIBS="${SPICE_SSL_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" OPENSSL_LIBS="${SPICE_SSL_LIBS}"

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
