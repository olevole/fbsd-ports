# $FreeBSD$

PORTNAME=	victoriametrics
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55.1
CATEGORIES=	net-mgmt

MAINTAINER=	nobody
COMMENT=	Fast, cost-effective and scalable time series database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git

USES=		gmake go:modules

USE_RC_SUBR=	victoria-metrics

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
	cd ${WRKSRC} && GOOS=freebsd ${GMAKE} victoria-metrics-pure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/victoria-metrics-pure ${STAGEDIR}${PREFIX}/bin/victoria-metrics-pure
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/victoria-metrics \
		${STAGEDIR}${VICTORIA_DATA} \
		${VICTORIA_DATA}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${PREFIX}/share/doc/victoria-metrics/

.include <bsd.port.mk>
