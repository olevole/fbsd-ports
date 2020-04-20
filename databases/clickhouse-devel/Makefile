# Created by: proler@gmail.com
# $FreeBSD: head/databases/clickhouse/Makefile 530566 2020-04-04 07:23:29Z sunpoet $

PORTNAME=	clickhouse
PORTVERSION=	20.4.1.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-prestable
CATEGORIES=	databases
PKGNAMESUFFIX?=	-devel

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

USES=		cmake:insource python shebangfix
CXX=		clang++90

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TAGNAME=	61d33a8
GH_TUPLE+=	\
		apache:arrow:b789226:apache_arrow/contrib/arrow \
		ClickHouse-Extras:avro:6cfcf6c:ClickHouse_Extras/contrib/avro \
		aws:aws-sdk-cpp:e4e87d2:aws_aws_sdk_cpp/contrib/aws \
		awslabs:aws-c-common:f71fc50:awslabs_aws_c_common/contrib/aws-c-common \
		awslabs:aws-c-event-stream:32713d3:awslabs_aws_c_event_stream/contrib/aws-c-event-stream \
		awslabs:aws-checksums:519d6d9:awslabs_aws_checksums/contrib/aws-checksums \
		powturbo:Turbo-Base64:95ba56a:powturbo_Turbo_Base64/contrib/base64 \
		ClickHouse-Extras:boost:5c6e801:ClickHouse_Extras_boost/contrib/boost \
		google:brotli:f83aa51:google_brotli/contrib/brotli \
		capnproto:capnproto:a00ccd9:capnproto_capnproto/contrib/capnproto \
		ClickHouse-Extras:cctz:b820d31:ClickHouse_Extras_cctz/contrib/cctz \
		ClickHouse-Extras:cppkafka:9b184d8:ClickHouse_Extras_cppkafka/contrib/cppkafka \
		curl:curl:b81e0b0:curl_curl/contrib/curl \
		google:double-conversion:cf2f0f3:google_double_conversion/contrib/double-conversion \
		ClickHouse-Extras:fastops:88752a5:ClickHouse_Extras_fastops/contrib/fastops \
		google:flatbuffers:bf9eb67:google_flatbuffers/contrib/flatbuffers \
		google:googletest:703bd9c:google_googletest/contrib/googletest \
		ClickHouse-Extras:grpc:c1d1765:ClickHouse_Extras_grpc/contrib/grpc \
		abseil:abseil-cpp:74d9175:abseil_abseil_cpp/contrib/grpc/third_party/abseil-cpp \
		google:benchmark:090faec:google_benchmark/contrib/grpc/third_party/benchmark \
		google:bloaty:73594cd:google_bloaty/contrib/grpc/third_party/bloaty \
		google:googletest:a2b8a8e:google_googletest/contrib/grpc/third_party/bloaty/third_party/googletest \
		google:re2:c964d9b:google_re2/contrib/grpc/third_party/bloaty/third_party/re2 \
		google:boringssl:7f02881:google_boringssl/contrib/grpc/third_party/boringssl \
		google:/boringssl:83da28a:google_boringssl/contrib/grpc/third_party/boringssl-with-bazel \
		c-ares:c-ares:e982924:c_ares_c_ares/contrib/grpc/third_party/cares/cares \
		envoyproxy:data-plane-api:c181f78:envoyproxy_data_plane_api/contrib/grpc/third_party/envoy-api \
		gflags:gflags:28f50e0:gflags_gflags/contrib/grpc/third_party/gflags \
		googleapis:googleapis:80ed4d0:googleapis_googleapis/contrib/grpc/third_party/googleapis \
		google:/googletest:c9ccac7:google_googletest/contrib/grpc/third_party/googletest \
		google:protobuf:0974557:google_protobuf/contrib/grpc/third_party/protobuf \
		google:googletest:5ec7f0c:google_protobuf/contrib/grpc/third_party/protobuf/third_party/googletest \
		envoyproxy:protoc-gen-validate:e143189:envoyproxy_protoc_gen_validate/contrib/grpc/third_party/protoc-gen-validate \
		cncf:udpa:9432480:cncf_udpa/contrib/grpc/third_party/udpa \
		madler:zlib:cacf7f1:madler_zlib/contrib/grpc/third_party/zlib  \
		c-ares:c-ares:c498c53:c_ares_c_ares/contrib/grpc/third_party/cares/cares \
		uber:h3:6cfd649:uber_h3/contrib/h3 \
		ClickHouse-Extras:hyperscan:3058c9c:ClickHouse_Extras_hyperscan/contrib/hyperscan \
		unicode-org:icu:faa2f9f:unicode_org_icu/contrib/icu \
		ClickHouse-Extras:icudata:f020820:ClickHouse_Extras_icudata/contrib/icudata \
		jemalloc:jemalloc:cd2931a:jemalloc_jemalloc/contrib/jemalloc \
		ClickHouse-Extras:libc-headers:92c74f9:ClickHouse_Extras_libc_headers/contrib/libc-headers \
		ClickHouse-Extras:libcxx:9f71e12:ClickHouse_Extras_libcxx/contrib/libcxx \
		ClickHouse-Extras:libcxxabi:1ebc83a:ClickHouse_Extras_libcxxabi/contrib/libcxxabi \
		ClickHouse-Extras:libgsasl:42ef206:ClickHouse_Extras_libgsasl/contrib/libgsasl \
		ClickHouse-Extras:libhdfs3:e2131aa:ClickHouse_Extras_libhdfs3/contrib/libhdfs3 \
		edenhill:librdkafka:4ffe54b:edenhill_librdkafka/contrib/librdkafka \
		ClickHouse-Extras:libunwind:ede0062:ClickHouse_Extras_libunwind/contrib/libunwind \
		GNOME:libxml2:18890f4:GNOME_libxml2/contrib/libxml2 \
		ClickHouse-Extras:llvm:5dab18f:ClickHouse_Extras_llvm/contrib/llvm \
		lz4:lz4:3d67671:lz4_lz4/contrib/lz4 \
		ClickHouse-Extras:mariadb-connector-c:3f512fe:ClickHouse_Extras_mariadb_connector_c/contrib/mariadb-connector-c \
		msgpack:msgpack-c:4668426:msgpack_msgpack_c/contrib/msgpack-c \
		boostorg:predef:560ff52:boostorg_predef/contrib/msgpack-c/external/boost/predef \
		boostorg:preprocessor:56090c5:boostorg_preprocessor/contrib/msgpack-c/external/boost/preprocessor \
		ClickHouse-Extras:openssl:07e9623:ClickHouse_Extras_openssl/contrib/openssl \
		apache:orc:5981208:apache_orc/contrib/orc \
		ClickHouse-Extras:poco:7d605a1:ClickHouse_Extras_poco/contrib/poco \
		ClickHouse-Extras:protobuf:d6a10dd:ClickHouse_Extras_protobuf/contrib/protobuf \
		Tencent:rapidjson:01950eb:Tencent_rapidjson/contrib/rapidjson \
		google:googletest:ba96d0b:google_googletest/contrib/rapidjson/thirdparty/gtest \
		google:re2:7cf8b88:google_re2/contrib/re2 \
		ClickHouse-Extras:replxx:f133262:ClickHouse_Extras_replxx/contrib/replxx \
		ClickHouse-Extras:ryu:5b4a853:ClickHouse_Extras_ryu/contrib/ryu \
		lemire:simdjson:560f074:lemire_simdjson/contrib/simdjson \
		google:benchmark:8982e1e:google_benchmark/contrib/simdjson/dependencies/benchmark \
		DaveGamble:cJSON:c69134d:DaveGamble_cJSON/contrib/simdjson/dependencies/cJSON \
		mikeando:fastjson:485f994:mikeando_fastjson/contrib/simdjson/dependencies/fastjson \
		vivkin:gason:7aee524:vivkin_gason/contrib/simdjson/dependencies/gason \
		zserge:jsmn:18e9fe4:zserge_jsmn/contrib/simdjson/dependencies/jsmn \
		nlohmann:json:a015b78:lohmann_json/contrib/simdjson/dependencies/json \
		dropbox:json11:ec4e452:dropbox_json11/contrib/simdjson/dependencies/json11 \
		open-source-parsers:jsoncpp:0c1cc6e:open_source_parsers_jsoncpp/contrib/simdjson/dependencies/jsoncpp \
		Tencent:rapidjson:b32cd94:Tencent_rapidjson/contrib/simdjson/scalarvssimd/rapidjson \
		google:googletest:0a43962:google_googletest/contrib/simdjson/dependencies/rapidjson/thirdparty/gtest \
		chadaustin:sajson:2dcfd35:chadaustin_sajson/contrib/simdjson/dependencies/sajson \
		esnme:ujson4c:e14f3fd:esnme_ujson4c/contrib/simdjson/dependencies/ujson4c \
		google:snappy:3f194ac:google_snappy/contrib/snappy \
		sparsehash:sparsehash-c11:cf0bffa:sparsehash_sparsehash_c11/contrib/sparsehash-c11 \
		apache:thrift:010ccf0:apache_thrift/contrib/thrift \
		ClickHouse-Extras:UnixODBC:b0ad30f:ClickHouse_Extras_UnixODBC/contrib/unixodbc \
		ClickHouse-Extras:zlib-ng:bba56a7:ClickHouse_Extras_zlib_ng/contrib/zlib-ng \
		facebook:zstd:2555975:facebook_zstd/contrib/zstd \
		feathericons:feather:dca4f12:feathericons_feather/contrib/website/images/feathericons

USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	tests/clickhouse-test \
		tests/queries/0_stateless/00979_live_view_watch_live_with_subquery.py \
		tests/queries/0_stateless/00979_live_view_watch_live.py \
		tests/queries/0_stateless/00971_live_view_watch_http_heartbeat.py \
		tests/queries/0_stateless/00966_live_view_watch_events_http.py \
		tests/queries/0_stateless/00967_live_view_watch_http.py \
		tests/queries/0_stateless/00979_live_view_watch_live_moving_avg.py \
		tests/queries/0_stateless/00960_live_view_watch_events_live.py \
		tests/queries/0_stateless/00965_live_view_watch_heartbeat.py \
		tests/queries/0_stateless/00963_temporary_live_view_watch_live_timeout.py.disabled \
		tests/queries/0_stateless/00991_live_view_watch_http.python \
		tests/queries/0_stateless/00921_datetime64_compatibility.python \
		tests/queries/0_stateless/00962_temporary_live_view_watch_live.py \
		tests/queries/0_stateless/00990_hasToken.python \
		tests/queries/0_stateless/00970_live_view_watch_events_http_heartbeat.py \
		tests/queries/0_stateless/00964_live_view_watch_events_heartbeat.py \
		tests/performance/create_benchmark_page.py

CMAKE_ARGS=	-DNO_WERROR=1 \
		-DUSE_INTERNAL_PROTOBUF_LIBRARY=FALSE \
		-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/

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

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/programs/server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxx.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxxabi.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libunwind.a
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

do-test-TEST-on:
	cd ${WRKSRC} && ctest -j4 -V

.include <bsd.port.post.mk>
