#ifndef SRC__HANDYSTATS_HPP
#define SRC__HANDYSTATS_HPP

#include <cstdio>
#include <string>

#include <handystats/measuring_points.hpp>
#include <handystats/core.hpp>
#include <handystats/json_dump.hpp>

// REQUEST

inline void HANDY_MDS_REQUEST(const std::string& method) {
	char metric_name[256];

	sprintf(metric_name, "mds.%s", method.c_str());
	HANDY_COUNTER_INCREMENT(metric_name);
}

inline void HANDY_MDS_UPLOAD() {
	HANDY_MDS_REQUEST("upload");
}

inline void HANDY_MDS_GET() {
	HANDY_MDS_REQUEST("get");
}

inline void HANDY_MDS_DELETE() {
	HANDY_MDS_REQUEST("delete");
}

inline void HANDY_MDS_DOWNLOAD_INFO() {
	HANDY_MDS_REQUEST("download_info");
}

inline void HANDY_MDS_PING() {
	HANDY_MDS_REQUEST("ping");
}

inline void HANDY_MDS_CACHE() {
	HANDY_MDS_REQUEST("cache");
}

inline void HANDY_MDS_CACHE_UPDATE() {
	HANDY_MDS_REQUEST("cache_update");
}

// REPLY

inline void HANDY_MDS_REPLY(const std::string& method, const int& code) {
	char metric_name[256];

	sprintf(metric_name, "mds.%s.%d", method.c_str(), code);
	HANDY_COUNTER_INCREMENT(metric_name);

	sprintf(metric_name, "mds.%s.%dx", method.c_str(), code / 10);
	HANDY_COUNTER_INCREMENT(metric_name);

	sprintf(metric_name, "mds.%d", code);
	HANDY_COUNTER_INCREMENT(metric_name);

	sprintf(metric_name, "mds.%dx", code / 10);
	HANDY_COUNTER_INCREMENT(metric_name);
}

inline void HANDY_MDS_UPLOAD_REPLY(const int& code) {
	HANDY_MDS_REPLY("upload", code);
}

inline void HANDY_MDS_GET_REPLY(const int& code) {
	HANDY_MDS_REPLY("get", code);
}

inline void HANDY_MDS_DELETE_REPLY(const int& code) {
	HANDY_MDS_REPLY("delete", code);
}

inline void HANDY_MDS_DOWNLOAD_INFO_REPLY(const int& code) {
	HANDY_MDS_REPLY("download_info", code);
}

inline void HANDY_MDS_PING_REPLY(const int& code) {
	HANDY_MDS_REPLY("ping", code);
}

inline void HANDY_MDS_CACHE_REPLY(const int& code) {
	HANDY_MDS_REPLY("cache", code);
}

inline void HANDY_MDS_CACHE_UPDATE_REPLY(const int& code) {
	HANDY_MDS_REPLY("cache_update", code);
}

#endif // SRC__HANDYSTATS_HPP
