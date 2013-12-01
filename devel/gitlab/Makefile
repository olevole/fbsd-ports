# $FreeBSD$

PORTNAME=	gitlab
PORTVERSION=	6.3.0
CATEGORIES=	devel
MASTER_SITES=	GH \
		http://jb1.olevole.ru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Self hosted Git management software

USE_GITHUB=	yes
GH_ACCOUNT=	gitlabhq
GH_PROJECT=	gitlabhq
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	cf4f36d

#BUILD_DEPENDS+=	gitolite:${PORTSDIR}/devel/gitolite

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		sudo:${PORTSDIR}/security/sudo \
		redis-server:${PORTSDIR}/databases/redis \
		${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems \
		${LOCALBASE}/bin/bundle:${PORTSDIR}/sysutils/rubygem-bundler \
		git:${PORTSDIR}/devel/git
#		charlock_holmes:${PORTSDIR}/textproc/rubygem-charlock_holmes \
#		unicorn:${PORTSDIR}/www/rubygem-unicorn

LIB_DEPENDS=	icuuc:${PORTSDIR}/devel/icu

USE_RUBY=	yes
USE_PYTHON=	2.7
USE_MYSQL=	server

GITLAB_USER=	git
GITLAB_GROUP=	git
GITLAB_MYSQL_DB=	gitlab
GITLAB_MYSQL_USER=	${GITLAB_USER}
GITLAB_MYSQL_PASS=	gitlab

#GIT_HOME=	${PREFIX}/git
GIT_HOME=	/usr/home/git

WWWDIR=		${GIT_HOME}/gitlab

#GEMS_VERSION=	1.8.25
#GEMS_DISTNAME=	rubygems-${GEMS_VERSION}
#GEMS_FILENAME=	${GEMS_DISTNAME}.tgz

USE_RC_SUBR=	gitlab

SUB_FILES=	gitlab pkg-deinstall gitlab_install.sh mysql_setup.sql nginx.example apache.example
SUB_LIST=	GITLAB_USER=${GITLAB_USER} \
		GIT_HOME=${GIT_HOME} \
		GITLAB_MYSQL_DB=${GITLAB_MYSQL_DB} \
		GITLAB_MYSQL_USER=${GITLAB_MYSQL_USER} \
		GITLAB_MYSQL_PASS=${GITLAB_MYSQL_PASS}

USERS=		git
GROUPS=		${GITLAB_GROUP}

NO_STAGE=	yes

.include <bsd.port.pre.mk>

#post-patch:
do-build:
	@${CP} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml
	@${REINPLACE_CMD} -e 's|/usr/bin/git|${LOCALBASE}/bin/git|g' ${WRKSRC}/config/gitlab.yml
	@${CP} ${WRKSRC}/config/database.yml.mysql ${WRKSRC}/config/database.yml
	@${REINPLACE_CMD} -e 's|gitlabhq_production|${GITLAB_MYSQL_DB}|g' ${WRKSRC}/config/database.yml
	@${REINPLACE_CMD} -e 's|root|${GITLAB_MYSQL_USER}|g' ${WRKSRC}/config/database.yml
	@${REINPLACE_CMD} -e 's|secure password|${GITLAB_MYSQL_PASS}|g' ${WRKSRC}/config/database.yml

do-install:
	@pw groupadd ${GITLAB_GROUP} ||true
	@pw useradd ${GITLAB_USER} -g ${GITLAB_GROUP} -d ${WWWDIR} -m -s /sbin/nologin -c 'GitLab' ||true
	@(mkdir -p ${WWWDIR}/.ssh && ${CHOWN} -R ${GITLAB_USER}:${GITLAB_USER} ${WWWDIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	@${CHOWN} -R ${GITLAB_USER}:${GITLAB_GROUP} ${WWWDIR}
	@su -m ${GITLAB_USER} -c "ssh-keygen -q -N '' -t rsa -f ${WWWDIR}/.ssh/id_rsa"
	@${MKDIR} ${GIT_HOME}
	@${CHOWN} ${GITLAB_USER}:${GITLAB_USER} ${GIT_HOME}
#	@(rm -R ${LOCALBASE}/git && ln -s ${GIT_HOME} ${LOCALBASE}/)
#	@(cd ${GIT_HOME} && su -m git -c "git clone -b gl-v320 https://github.com/gitlabhq/gitolite.git gitolite")
	@(cd ${GIT_HOME} && su -m ${USERS} -c "git clone https://github.com/gitlab-freebsd/gitlab-shell.git")
	@${FIND} -f ${WWWDIR} ${GIT_HOME}/gitlab-shell/ -type f | \
	    (while read i; do \
		if ( ${CAT} $$i | ${GREP} "\"/home/git" >/dev/null 2>&1 ); then \
		${SED} -i.orig s:"/home/git:"/usr/home/git:g $$i; \
		fi \
	    done)
	@(cd ${GIT_HOME}/gitlab-shell && su -m ${USERS} -c "cp config.yml.example config.yml" && su -m ${USERS} -c "ee config.yml" && su -m ${USERS} -c "./bin/install")
	@su -m ${USERS} -c "${MKDIR} ${GIT_HOME}/bin"
	@su -m ${USERS} -c "sh -c echo "PATH=$$PATH:${GIT_HOME}/bin"" >> ${GIT_HOME}/.profile
	@su -m ${USERS} -c "sh -c echo "export PATH"" >> ${GIT_HOME}/.profile
#	@sudo -u git -H sh -c '${GIT_HOME}/gitolite/install -ln ${GIT_HOME}/bin'
	@cp ${WWWDIR}/.ssh/id_rsa.pub ${GIT_HOME}/gitlab.pub
	@${CHMOD} 0444 ${GIT_HOME}/gitlab.pub
#	@su -m git -c "sh -c "PATH=${GIT_HOME}/bin:$$PATH; su -m git -c "sh -c "gitolite setup -pk ${GIT_HOME}/gitlab.pub""""
#	@${CHMOD} 750 ${GIT_HOME}/.gitolite/
	@${CHOWN} -R ${GITLAB_USER}:${GITLAB_USER} ${GIT_HOME}
	@${CHMOD} -R ug+rwX,o-rwx ${GIT_HOME}/repositories/
	@${CHOWN} -R ${GITLAB_USER}:${GITLAB_USER} ${GIT_HOME}/repositories/
	@su -m ${USERS} -c "find ${GIT_HOME}/repositories -type d -print0 | xargs -0 chmod g+s"
	@su -m ${GITLAB_USER} -c "ssh-keyscan -t rsa,dsa localhost" >> ${WWWDIR}/.ssh/known_hosts
	@su -m ${GITLAB_USER} -c "ssh-keyscan -t rsa,dsa 127.0.0.1" >> ${WWWDIR}/.ssh/known_hosts
	@${CHOWN} -R ${GITLAB_USER} ${WWWDIR}/log ${WWWDIR}/tmp
	@${CHMOD} -R u+rwX  ${WWWDIR}/log ${WWWDIR}/tmp
	@su -m ${GITLAB_USER} -c "${MKDIR} ${WWWDIR}/gitlab-satellites"
#	@gem19 install bundler
#	@gem19 install charlock_holmes --version '0.6.9'
	@${REINPLACE_CMD} -e 's|source "https://rubygems.org"|source "http://rubygems.org"|g' ${WWWDIR}/Gemfile
	@(cd ${WWWDIR} && su -m ${GITLAB_USER} -c "bundle install --deployment --without development test postgres")
	@${MKDIR} ${WWWDIR}/distrib
	@${CP} ${WRKDIR}/mysql_setup.sql ${WWWDIR}/distrib/
	@${CP} ${WRKDIR}/nginx.example ${WWWDIR}/distrib/
	@${CP} ${WRKDIR}/apache.example ${WWWDIR}/distrib/
	@${INSTALL_SCRIPT} ${WRKDIR}/gitlab_install.sh ${WWWDIR}/distrib/

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -r 's|%%WWWDIR%%|${WWWDIR}|g' | ${SED} -r 's|%%PREFIX%%|${LOCALBASE}|g'
	@${FIND} -f ${WWWDIR} ${GIT_HOME}/gitlab-shell -type f | \
	    (while read i; do \
		if ( ${CAT} $$i | ${GREP} "#!/bin/bash" >/dev/null 2>&1 ); then \
		    ${SED} -i.orig s:/bin/bash:${LOCALBASE}/bin/bash/:g $$i; \
		fi \
	    done)
#	@${PATCH} -d ${WWWDIR}/app/views/devise/sessions/ < ${FILESDIR}/extra-patch-new.html.haml
	@${FIND} -s ${WWWDIR} -not -type d | \
	${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d | ${SORT} -r | \
	${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
