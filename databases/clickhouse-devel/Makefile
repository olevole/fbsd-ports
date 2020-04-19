# Created by: proler@gmail.com
# $FreeBSD: head/databases/clickhouse/Makefile 530566 2020-04-04 07:23:29Z sunpoet $

PORTNAME=	clickhouse
PORTVERSION=	20.4.1.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-prestable
PKGNAMESUFFIX?= -devel
CATEGORIES=	databases

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

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TAGNAME=	61d33a8
GH_TUPLE+=	\
		apache:arrow:3cbcb7b:apache_arrow/contrib/arrow \
		ClickHouse-Extras:avro:6cfcf6c:ClickHouse_Extras/contrib/avro \
		aws:aws-sdk-cpp:e4e87d2:aws_aws_sdk_cpp/contrib/aws \
		awslabs:aws-c-common:f71fc50:awslabs_aws_c_common/contrib/aws-c-common \
		awslabs:aws-c-event-stream:32713d3:awslabs_aws_c_event_stream/contrib/aws-c-event-stream \
		awslabs:aws-checksums:519d6d9:awslabs_aws_checksums/contrib/aws-checksums \
		powturbo:Turbo-Base64:95ba56a:powturbo_Turbo_Base64/contrib/base64 \
		ClickHouse-Extras:boost:5c6e801:ClickHouse_Extras_boost/contrib/boost \
		google:brotli:f83aa51:google_brotli/contrib/brotli \
		capnproto:capnproto:206db62:capnproto_capnproto/contrib/capnproto \
		ClickHouse-Extras:cctz:b820d31:ClickHouse_Extras_cctz/contrib/cctz \
		ClickHouse-Extras:cppkafka:9b184d8:ClickHouse_Extras_cppkafka/contrib/cppkafka \
		curl:curl:b81e0b0:curl_curl/contrib/curl \
		google:double-conversion:5fa81e8:google_double_conversion/contrib/double-conversion \
		ClickHouse-Extras:fastops:88752a5:ClickHouse_Extras_fastops/contrib/fastops \
		google:flatbuffers:cb4d0f7:google_flatbuffers/contrib/flatbuffers \
		google:googletest:703bd9c:google_googletest/contrib/googletest \
		ClickHouse-Extras:grpc:a2af2c9:ClickHouse_Extras_grpc/contrib/grpc \
		c-ares:c-ares:c498c53:c_ares_c_ares/contrib/grpc/third_party/cares/cares \
		uber:h3:8e745ce:uber_h3/contrib/h3 \
		ClickHouse-Extras:hyperscan:3058c9c:ClickHouse_Extras_hyperscan/contrib/hyperscan \
		unicode-org:icu:b0fb483:unicode_org_icu/contrib/icu \
		ClickHouse-Extras:icudata:f020820:ClickHouse_Extras_icudata/contrib/icudata \
		jemalloc:jemalloc:4f8efba:jemalloc_jemalloc/contrib/jemalloc \
		ClickHouse-Extras:libc-headers:92c74f9:ClickHouse_Extras_libc_headers/contrib/libc-headers \
		ClickHouse-Extras:libcxx:9f71e12:ClickHouse_Extras_libcxx/contrib/libcxx \
		ClickHouse-Extras:libcxxabi:1ebc83a:ClickHouse_Extras_libcxxabi/contrib/libcxxabi \
		ClickHouse-Extras:libgsasl:42ef206:ClickHouse_Extras_libgsasl/contrib/libgsasl \
		ClickHouse-Extras:libhdfs3:3f308e5:ClickHouse_Extras_libhdfs3/contrib/libhdfs3 \
		edenhill:librdkafka:3c8cc41:edenhill_librdkafka/contrib/librdkafka \
		ClickHouse-Extras:libunwind:ede0062:ClickHouse_Extras_libunwind/contrib/libunwind \
		GNOME:libxml2:e4fb368:GNOME_libxml2/contrib/libxml2 \
		ClickHouse-Extras:llvm:5dab18f:ClickHouse_Extras_llvm/contrib/llvm \
		lz4:lz4:f39b79f:lz4_lz4/contrib/lz4 \
		ClickHouse-Extras:mariadb-connector-c:3f512fe:ClickHouse_Extras_mariadb_connector_c/contrib/mariadb-connector-c \
		msgpack:msgpack-c:102dba8:msgpack_msgpack_c/contrib/msgpack-c \
		ClickHouse-Extras:openssl:07e9623:ClickHouse_Extras_openssl/contrib/openssl \
		apache:orc:7654764:apache_orc/contrib/orc \
		ClickHouse-Extras:poco:7d605a1:ClickHouse_Extras_poco/contrib/poco \
		ClickHouse-Extras:protobuf:d6a10dd:ClickHouse_Extras_protobuf/contrib/protobuf \
		Tencent:rapidjson:8f4c021:Tencent_rapidjson/contrib/rapidjson \
		google:re2:a5c78ae:google_re2/contrib/re2 \
		ClickHouse-Extras:replxx:f133262:ClickHouse_Extras_replxx/contrib/replxx \
		ClickHouse-Extras:ryu:5b4a853:ClickHouse_Extras_ryu/contrib/ryu \
		lemire:simdjson:bd9628d:lemire_simdjson/contrib/simdjson \
		DaveGamble:cJSON:39853e5:DaveGamble_cJSON/contrib/simdjson/dependencies/cJSON \
		mikeando:fastjson:485f994:mikeando_fastjson/contrib/simdjson/dependencies/fastjson \
		vivkin:gason:7aee524:vivkin_gason/contrib/simdjson/dependencies/gason \
		zserge:jsmn:053d3cd:zserge_jsmn/contrib/simdjson/dependencies/jsmn \
		nlohmann:json:be13760:lohmann_json/contrib/simdjson/dependencies/json \
		dropbox:json11:2df9473:dropbox_json11/contrib/simdjson/dependencies/json11 \
		Tencent:rapidjson:8f4c021:Tencent_rapidjson/contrib/simdjson/scalarvssimd/rapidjson \
		chadaustin:sajson:2961568:chadaustin_sajson/contrib/simdjson/dependencies/sajson \
		esnme:ujson4c:e14f3fd:esnme_ujson4c/contrib/simdjson/dependencies/ujson4c \
		google:snappy:251d935:google_snappy/contrib/snappy \
		sparsehash:sparsehash-c11:88b354f:sparsehash_sparsehash_c11/contrib/sparsehash-c11 \
		apache:thrift:9e864d5:apache_thrift/contrib/thrift \
		ClickHouse-Extras:UnixODBC:b0ad30f:ClickHouse_Extras_UnixODBC/contrib/unixodbc \
		ClickHouse-Extras:zlib-ng:bba56a7:ClickHouse_Extras_zlib_ng/contrib/zlib-ng \
		facebook:zstd:5b0a452:facebook_zstd/contrib/zstd \
		feathericons:feather:b15b4a7:feathericons_feather/contrib/website/images/feathericons

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
#.if ${PORT_OPTIONS:MTEST} && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300014
#BROKEN=	fails to compile with Clang 8: Assertion error in getZExtValue()
#.endif

.include <bsd.port.pre.mk>

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
