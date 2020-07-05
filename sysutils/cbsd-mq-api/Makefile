# Created by: olevole@olevole.ru
# $FreeBSD: $

PORTNAME=	cbsd-mq-api
DISTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	CBSD message queue API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
GH_TAGNAME=	56de119
USE_RC_SUBR=	cbsd-mq-api
SSP_UNSAFE=	yes

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cbsd-mq-api ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
