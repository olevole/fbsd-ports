# Created by: Oleg Ginzburg <olevole@olevole.ru>
# $FreeBSD: head/sysutils/ioping/Makefile 327772 2013-09-20 23:05:58Z bapt $

PORTNAME=	ioping
PORTVERSION=	0.8
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simple disk I/0 latency measuring tool

LICENSE=	GPLv3

MAN1=		ioping.1
PLIST_FILES=	bin/ioping

MAKE_ENV=	VERSION=${PORTVERSION}

# for the benefit of <80000
CFLAGS+=	-lm

do-build:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -DVERSION=${PORTVERSION} ioping.c -o ioping

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
