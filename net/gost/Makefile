PORTNAME=	gost
PORTVERSION=	2.11.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olevole@olevole.ru
COMMENT=	GO Simple Tunnel - a simple tunnel written in golang
WWW=		https://github.com/ginuerzh/gost

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_TARGET=	./cmd/gost

USE_GITHUB=	yes
USE_GITLAB=	nodefault
GH_ACCOUNT=	ginuerzh
GH_PROJECT=	${PORTNAME}

.include "${.CURDIR}/../gost/Makefile.deps"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
