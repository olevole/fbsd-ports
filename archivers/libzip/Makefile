# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD: head/archivers/libzip/Makefile 309150 2012-12-18 07:57:31Z danfe $

PORTNAME=	libzip
PORTVERSION=	0.11.1
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.nih.at/libzip/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	C library for reading, creating, and modifying ZIP archives

GNU_CONFIGURE=	yes
MAKE_ENV=	LC_ALL="C"
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

MAN1=		zipcmp.1 \
		zipmerge.1 \
		ziptorrent.1

MAN3=           libzip.3 \
                zip_add.3 \
                zip_add_dir.3 \
                zip_close.3 \
                zip_delete.3 \
                zip_dir_add.3 \
                zip_discard.3 \
                zip_error_clear.3 \
                zip_error_get.3 \
                zip_error_get_sys_type.3 \
                zip_error_to_str.3 \
                zip_errors.3 \
                zip_fclose.3 \
                zip_fdopen.3 \
                zip_file_add.3 \
                zip_file_error_clear.3 \
                zip_file_error_get.3 \
                zip_file_strerror.3 \
                zip_file_extra_field_delete.3 \
                zip_file_extra_field_delete_by_id.3 \
                zip_file_extra_field_get.3 \
                zip_file_extra_field_get_by_id.3 \
                zip_file_extra_field_set.3 \
                zip_file_extra_fields_count.3 \
                zip_file_extra_fields_count_by_id.3 \
                zip_file_get_comment.3 \
                zip_file_rename.3 \
                zip_file_replace.3 \
                zip_file_set_comment.3 \
                zip_fopen.3 \
                zip_fopen_encrypted.3 \
                zip_fopen_index.3 \
                zip_fopen_index_encrypted.3 \
                zip_fread.3 \
                zip_get_archive_comment.3 \
                zip_get_archive_flag.3 \
                zip_get_file_comment.3 \
                zip_get_name.3 \
                zip_get_num_entries.3 \
                zip_get_num_files.3 \
                zip_name_locate.3 \
                zip_open.3 \
                zip_rename.3 \
                zip_replace.3 \
                zip_set_archive_comment.3 \
                zip_set_archive_flag.3 \
                zip_set_file_compression.3 \
                zip_set_default_password.3 \
                zip_set_file_comment.3 \
                zip_source_buffer.3 \
                zip_source_file.3 \
                zip_source_filep.3 \
                zip_source_free.3 \
                zip_source_function.3 \
                zip_source_zip.3 \
                zip_stat.3 \
                zip_stat_index.3 \
                zip_stat_init.3 \
                zip_strerror.3 \
                zip_unchange.3 \
                zip_unchange_all.3 \
                zip_unchange_archive.3

.include <bsd.port.mk>
