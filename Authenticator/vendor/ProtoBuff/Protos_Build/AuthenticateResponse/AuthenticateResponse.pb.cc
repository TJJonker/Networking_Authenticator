// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AuthenticateResponse.proto

#include "pch.h"
#include "AuthenticateResponse.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Database {
constexpr AuthenticateResponse::AuthenticateResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : creationdate_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , requestid_(0)
  , userid_(0)
  , success_(false)
  , failreason_(1)
{}
struct AuthenticateResponseDefaultTypeInternal {
  constexpr AuthenticateResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~AuthenticateResponseDefaultTypeInternal() {}
  union {
    AuthenticateResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT AuthenticateResponseDefaultTypeInternal _AuthenticateResponse_default_instance_;
}  // namespace Database
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_AuthenticateResponse_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_AuthenticateResponse_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_AuthenticateResponse_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_AuthenticateResponse_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, requestid_),
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, userid_),
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, failreason_),
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, success_),
  PROTOBUF_FIELD_OFFSET(::Database::AuthenticateResponse, creationdate_),
  1,
  2,
  4,
  3,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, -1, sizeof(::Database::AuthenticateResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Database::_AuthenticateResponse_default_instance_),
};

const char descriptor_table_protodef_AuthenticateResponse_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032AuthenticateResponse.proto\022\010Database\"\353"
  "\001\n\024AuthenticateResponse\022\021\n\trequestID\030\001 \002"
  "(\005\022\016\n\006userID\030\002 \001(\005\022=\n\nfailReason\030\004 \002(\0162)"
  ".Database.AuthenticateResponse.FailReaso"
  "n\022\017\n\007success\030\005 \002(\010\022\024\n\014creationDate\030\003 \001(\t"
  "\"J\n\nFailReason\022\010\n\004NONE\020\001\022\027\n\023INVALID_CRED"
  "ENTIALS\020\002\022\031\n\025INTERNAL_SERVER_ERROR\020\003"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_AuthenticateResponse_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_AuthenticateResponse_2eproto = {
  false, false, 276, descriptor_table_protodef_AuthenticateResponse_2eproto, "AuthenticateResponse.proto", 
  &descriptor_table_AuthenticateResponse_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_AuthenticateResponse_2eproto::offsets,
  file_level_metadata_AuthenticateResponse_2eproto, file_level_enum_descriptors_AuthenticateResponse_2eproto, file_level_service_descriptors_AuthenticateResponse_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_AuthenticateResponse_2eproto_getter() {
  return &descriptor_table_AuthenticateResponse_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_AuthenticateResponse_2eproto(&descriptor_table_AuthenticateResponse_2eproto);
namespace Database {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AuthenticateResponse_FailReason_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_AuthenticateResponse_2eproto);
  return file_level_enum_descriptors_AuthenticateResponse_2eproto[0];
}
bool AuthenticateResponse_FailReason_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr AuthenticateResponse_FailReason AuthenticateResponse::NONE;
constexpr AuthenticateResponse_FailReason AuthenticateResponse::INVALID_CREDENTIALS;
constexpr AuthenticateResponse_FailReason AuthenticateResponse::INTERNAL_SERVER_ERROR;
constexpr AuthenticateResponse_FailReason AuthenticateResponse::FailReason_MIN;
constexpr AuthenticateResponse_FailReason AuthenticateResponse::FailReason_MAX;
constexpr int AuthenticateResponse::FailReason_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class AuthenticateResponse::_Internal {
 public:
  using HasBits = decltype(std::declval<AuthenticateResponse>()._has_bits_);
  static void set_has_requestid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_userid(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_failreason(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_success(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_creationdate(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000001a) ^ 0x0000001a) != 0;
  }
};

AuthenticateResponse::AuthenticateResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Database.AuthenticateResponse)
}
AuthenticateResponse::AuthenticateResponse(const AuthenticateResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  creationdate_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_creationdate()) {
    creationdate_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_creationdate(), 
      GetArenaForAllocation());
  }
  ::memcpy(&requestid_, &from.requestid_,
    static_cast<size_t>(reinterpret_cast<char*>(&failreason_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(failreason_));
  // @@protoc_insertion_point(copy_constructor:Database.AuthenticateResponse)
}

void AuthenticateResponse::SharedCtor() {
creationdate_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&requestid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&success_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(success_));
failreason_ = 1;
}

AuthenticateResponse::~AuthenticateResponse() {
  // @@protoc_insertion_point(destructor:Database.AuthenticateResponse)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void AuthenticateResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  creationdate_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void AuthenticateResponse::ArenaDtor(void* object) {
  AuthenticateResponse* _this = reinterpret_cast< AuthenticateResponse* >(object);
  (void)_this;
}
void AuthenticateResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void AuthenticateResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void AuthenticateResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:Database.AuthenticateResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    creationdate_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x0000001eu) {
    ::memset(&requestid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&success_) -
        reinterpret_cast<char*>(&requestid_)) + sizeof(success_));
    failreason_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AuthenticateResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 requestID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_requestid(&has_bits);
          requestid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 userID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_userid(&has_bits);
          userid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional string creationDate = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_creationdate();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Database.AuthenticateResponse.creationDate");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required .Database.AuthenticateResponse.FailReason failReason = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::Database::AuthenticateResponse_FailReason_IsValid(val))) {
            _internal_set_failreason(static_cast<::Database::AuthenticateResponse_FailReason>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(4, val, mutable_unknown_fields());
          }
        } else
          goto handle_unusual;
        continue;
      // required bool success = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_success(&has_bits);
          success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* AuthenticateResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Database.AuthenticateResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 requestID = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_requestid(), target);
  }

  // optional int32 userID = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_userid(), target);
  }

  // optional string creationDate = 3;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_creationdate().data(), static_cast<int>(this->_internal_creationdate().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "Database.AuthenticateResponse.creationDate");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_creationdate(), target);
  }

  // required .Database.AuthenticateResponse.FailReason failReason = 4;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_failreason(), target);
  }

  // required bool success = 5;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_success(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Database.AuthenticateResponse)
  return target;
}

size_t AuthenticateResponse::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Database.AuthenticateResponse)
  size_t total_size = 0;

  if (_internal_has_requestid()) {
    // required int32 requestID = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());
  }

  if (_internal_has_success()) {
    // required bool success = 5;
    total_size += 1 + 1;
  }

  if (_internal_has_failreason()) {
    // required .Database.AuthenticateResponse.FailReason failReason = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_failreason());
  }

  return total_size;
}
size_t AuthenticateResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Database.AuthenticateResponse)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000001a) ^ 0x0000001a) == 0) {  // All required fields are present.
    // required int32 requestID = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());

    // required bool success = 5;
    total_size += 1 + 1;

    // required .Database.AuthenticateResponse.FailReason failReason = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_failreason());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string creationDate = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_creationdate());
  }

  // optional int32 userID = 2;
  if (cached_has_bits & 0x00000004u) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_userid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AuthenticateResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    AuthenticateResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AuthenticateResponse::GetClassData() const { return &_class_data_; }

void AuthenticateResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<AuthenticateResponse *>(to)->MergeFrom(
      static_cast<const AuthenticateResponse &>(from));
}


void AuthenticateResponse::MergeFrom(const AuthenticateResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Database.AuthenticateResponse)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_creationdate(from._internal_creationdate());
    }
    if (cached_has_bits & 0x00000002u) {
      requestid_ = from.requestid_;
    }
    if (cached_has_bits & 0x00000004u) {
      userid_ = from.userid_;
    }
    if (cached_has_bits & 0x00000008u) {
      success_ = from.success_;
    }
    if (cached_has_bits & 0x00000010u) {
      failreason_ = from.failreason_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AuthenticateResponse::CopyFrom(const AuthenticateResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Database.AuthenticateResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AuthenticateResponse::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void AuthenticateResponse::InternalSwap(AuthenticateResponse* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &creationdate_, lhs_arena,
      &other->creationdate_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(AuthenticateResponse, success_)
      + sizeof(AuthenticateResponse::success_)
      - PROTOBUF_FIELD_OFFSET(AuthenticateResponse, requestid_)>(
          reinterpret_cast<char*>(&requestid_),
          reinterpret_cast<char*>(&other->requestid_));
  swap(failreason_, other->failreason_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AuthenticateResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_AuthenticateResponse_2eproto_getter, &descriptor_table_AuthenticateResponse_2eproto_once,
      file_level_metadata_AuthenticateResponse_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Database
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Database::AuthenticateResponse* Arena::CreateMaybeMessage< ::Database::AuthenticateResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Database::AuthenticateResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
