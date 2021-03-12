# $FreeBSD$

PORTNAME=	vmutils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55.1
CATEGORIES=	net-mgmt

MAINTAINER=	nobody
COMMENT=	Fast, cost-effective and scalable time series database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git

USES=		gmake go:modules

USE_RC_SUBR=	vmagent

USERS=		victoria-metrics
GROUPS=		victoria-metrics

VICTORIA_DATA?=	/var/db/victoria-metrics

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_USER=${USERS}

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_USER=${USERS}

GO_PKGNAME=	github.com/VictoriaMetrics/VictoriaMetrics
GO_BUILDFLAGS=	-ldflags "\
			-s -w \
			-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/lib/buildinfo.Version=VictoriaMetrics"

USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaMetrics
#GH_TUPLE=	\
#		golang:sys:eaf3bda374d2:golang_sys/vendor/golang.org/x/sys

do-build:
	cd ${WRKSRC} && GOOS=freebsd ${GMAKE} vmutils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmagent ${STAGEDIR}${PREFIX}/bin/vmagent
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmalert ${STAGEDIR}${PREFIX}/bin/vmalert
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmauth ${STAGEDIR}${PREFIX}/bin/vmauth
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmbackup ${STAGEDIR}${PREFIX}/bin/vmbackup
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmctl ${STAGEDIR}${PREFIX}/bin/vmctl
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmrestore ${STAGEDIR}${PREFIX}/bin/vmrestore

.include <bsd.port.mk>
