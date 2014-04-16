# $FreeBSD: $

PORTNAME=	litetran
PORTVERSION=	1.2
CATEGORIES=	x11 textproc
MASTER_SITES=	GH
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER=	olevole@olevole.ru
COMMENT=	LiteTran is tiny program for text translation.

USE_GITHUB=	yes
GH_ACCOUNT=	flareguner
GH_PROJECT=	${POSTNAME}
GH_COMMIT=	2d2c9bd

USE_QT5=	core widgets network multimedia linguisttools #11Extras
USES=		cmake

#STRIP_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.include <bsd.port.mk>
