# Created by: olevole@olevole.ru
# $FreeBSD: $

PORTNAME=	libspice-server
PORTVERSION=	0.14.0
CATEGORIES?=	devel
MASTER_SITES=	https://www.spice-space.org/download/releases/
DISTNAME=	spice-${PORTVERSION}

MAINTAINER=	olevole@olevole.ru
COMMENT?=	Implements the server side of the SPICE protocol

LICENSE=	GPLv2

USE_XORG=	pixman
USES=		autoreconf cpe gmake jpeg libtool pkgconfig tar:bzip2 \
		python ssl localbase:ldflags
CPE_VENDOR=	redhat

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR}
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol

CONFIGURE_ARGS+=--disable-celt051

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=	-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=	SSL_CFLAGS="${SPICE_SSL_CFLAGS}" SSL_LIBS="${SPICE_SSL_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" OPENSSL_LIBS="${SPICE_SSL_LIBS}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# we can't use pathfix with USES=autoreconf
MAKE_ARGS=	pkgconfigdir="$(PREFIX)/libdata/pkgconfig"

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
