# Created by: olevole@olevole.ru
# $FreeBSD: $

PORTNAME=	cbsd-mq-router
DISTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	CBSD message queue router

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	beanstalkd:net/beanstalkd

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
USE_RC_SUBR=	cbsd-mq-router
SSP_UNSAFE=	yes

SUB_FILES=	pkg-message

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

do-install:
	${MV} ${WRKSRC}/etc/cbsd-mq-router.json ${STAGEDIR}${PREFIX}/etc/cbsd-mq-router.json.sample
	${INSTALL_PROGRAM} ${WRKSRC}/cbsd-mq-router ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
