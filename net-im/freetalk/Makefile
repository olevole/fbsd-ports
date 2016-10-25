# Created by: Oleg Ginzburg  (olevole@olevole.ru)
# $FreeBSD: head/net-im/freetalk/Makefile 366777 2014-08-31 15:17:49Z tijl $

PORTNAME=	freetalk
PORTVERSION=	4.1
CATEGORIES=	net-im

MAINTAINER=	olevole@olevole.ru
COMMENT=	GNU console based Jabber client

OPTIONS_DEFINE=	NLS

LIB_DEPENDS=	libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth \
		libcurl.so:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	guile>=2.0:${PORTSDIR}/lang/guile2
RUN_DEPENDS=	guile>=2.0:${PORTSDIR}/lang/guile2 \
		curl:${PORTSDIR}/ftp/curl
USE_GITHUB=	yes
GH_ACCOUNT=	GNUFreetalk
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6ce50aa

USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_WITH=libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF= --disable-nls

pre-configure:
	cd ${WRKSRC} && /bin/sh ./autogen.sh

.include <bsd.port.mk>
