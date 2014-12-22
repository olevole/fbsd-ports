# $FreeBSD: $

PORTNAME=	litetran
PORTVERSION=	1.3
CATEGORIES=	x11 textproc
MASTER_SITES=	GH

MAINTAINER=	olevole@olevole.ru
COMMENT=	LiteTran is a tiny GUI for text translation

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

RUN_DEPENDS+=   ${LOCALBASE}/libdata/pkgconfig/dri.pc:${PORTSDIR}/graphics/dri

USE_GITHUB=	yes
GH_ACCOUNT=	flareguner
GH_PROJECT=	${POSTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	d099aa9

USE_QT5=	core widgets network multimedia linguisttools x11extras
USES=		cmake:outsource

.include <bsd.port.mk>
