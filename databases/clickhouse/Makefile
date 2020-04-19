# Created by: proler@gmail.com
# $FreeBSD: head/databases/clickhouse/Makefile 530566 2020-04-04 07:23:29Z sunpoet $

PORTNAME=	clickhouse
PORTVERSION=	20.4.1.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-prestable
CATEGORIES=	databases
DISTFILES=	

MAINTAINER=	ports@FreeBSD.Org
COMMENT=	ClickHouse is a column-oriented database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash \
		clang++90:devel/llvm90
LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	curl:ftp/curl \
		bash:shells/bash
CXX=		clang++90

USES:=		cmake:insource shebangfix

USE_LDCONFIG=	yes

#USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TAGNAME=	abbeb13
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	tests/performance/create_benchmark_page.py \
		tests/clickhouse-test

CMAKE_ARGS=	-DNO_WERROR=1 \
		-DUSE_INTERNAL_PROTOBUF_LIBRARY=FALSE \
		-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/ \

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
SOVERSION=	${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

# Building with tests fails on 13.0-CURRENT@r346346 amd64
# Clang segfaults with an assertion error - see PR #237619
.if ${PORT_OPTIONS:MTEST} && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300014
BROKEN=	fails to compile with Clang 8: Assertion error in getZExtValue()
.endif

.include <bsd.port.pre.mk>

do-extract:
	git clone --recursive --single-branch --depth=1 \
	https://github.com/ClickHouse/ClickHouse.git \
	${WRKSRC}
	(cd ${WRKSRC} && git submodule update --init --recursive)

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/programs/server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*

	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

do-test-TEST-on:
	cd ${WRKSRC} && ctest -j4 -V

.include <bsd.port.post.mk>
