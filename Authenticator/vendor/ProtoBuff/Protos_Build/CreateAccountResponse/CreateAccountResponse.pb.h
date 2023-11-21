// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CreateAccountResponse.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_CreateAccountResponse_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_CreateAccountResponse_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_CreateAccountResponse_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_CreateAccountResponse_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CreateAccountResponse_2eproto;
namespace Database {
class CreateAccountResponse;
struct CreateAccountResponseDefaultTypeInternal;
extern CreateAccountResponseDefaultTypeInternal _CreateAccountResponse_default_instance_;
}  // namespace Database
PROTOBUF_NAMESPACE_OPEN
template<> ::Database::CreateAccountResponse* Arena::CreateMaybeMessage<::Database::CreateAccountResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Database {

enum CreateAccountResponse_FailReason : int {
  CreateAccountResponse_FailReason_NONE = 1,
  CreateAccountResponse_FailReason_ACCOUNT_ALREADY_EXISTS = 2,
  CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR = 3
};
bool CreateAccountResponse_FailReason_IsValid(int value);
constexpr CreateAccountResponse_FailReason CreateAccountResponse_FailReason_FailReason_MIN = CreateAccountResponse_FailReason_NONE;
constexpr CreateAccountResponse_FailReason CreateAccountResponse_FailReason_FailReason_MAX = CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR;
constexpr int CreateAccountResponse_FailReason_FailReason_ARRAYSIZE = CreateAccountResponse_FailReason_FailReason_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CreateAccountResponse_FailReason_descriptor();
template<typename T>
inline const std::string& CreateAccountResponse_FailReason_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CreateAccountResponse_FailReason>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CreateAccountResponse_FailReason_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CreateAccountResponse_FailReason_descriptor(), enum_t_value);
}
inline bool CreateAccountResponse_FailReason_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CreateAccountResponse_FailReason* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CreateAccountResponse_FailReason>(
    CreateAccountResponse_FailReason_descriptor(), name, value);
}
// ===================================================================

class CreateAccountResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Database.CreateAccountResponse) */ {
 public:
  inline CreateAccountResponse() : CreateAccountResponse(nullptr) {}
  ~CreateAccountResponse() override;
  explicit constexpr CreateAccountResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CreateAccountResponse(const CreateAccountResponse& from);
  CreateAccountResponse(CreateAccountResponse&& from) noexcept
    : CreateAccountResponse() {
    *this = ::std::move(from);
  }

  inline CreateAccountResponse& operator=(const CreateAccountResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline CreateAccountResponse& operator=(CreateAccountResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CreateAccountResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const CreateAccountResponse* internal_default_instance() {
    return reinterpret_cast<const CreateAccountResponse*>(
               &_CreateAccountResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CreateAccountResponse& a, CreateAccountResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(CreateAccountResponse* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CreateAccountResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline CreateAccountResponse* New() const final {
    return new CreateAccountResponse();
  }

  CreateAccountResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<CreateAccountResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CreateAccountResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const CreateAccountResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CreateAccountResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Database.CreateAccountResponse";
  }
  protected:
  explicit CreateAccountResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef CreateAccountResponse_FailReason FailReason;
  static constexpr FailReason NONE =
    CreateAccountResponse_FailReason_NONE;
  static constexpr FailReason ACCOUNT_ALREADY_EXISTS =
    CreateAccountResponse_FailReason_ACCOUNT_ALREADY_EXISTS;
  static constexpr FailReason INTERNAL_SERVER_ERROR =
    CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR;
  static inline bool FailReason_IsValid(int value) {
    return CreateAccountResponse_FailReason_IsValid(value);
  }
  static constexpr FailReason FailReason_MIN =
    CreateAccountResponse_FailReason_FailReason_MIN;
  static constexpr FailReason FailReason_MAX =
    CreateAccountResponse_FailReason_FailReason_MAX;
  static constexpr int FailReason_ARRAYSIZE =
    CreateAccountResponse_FailReason_FailReason_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  FailReason_descriptor() {
    return CreateAccountResponse_FailReason_descriptor();
  }
  template<typename T>
  static inline const std::string& FailReason_Name(T enum_t_value) {
    static_assert(::std::is_same<T, FailReason>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function FailReason_Name.");
    return CreateAccountResponse_FailReason_Name(enum_t_value);
  }
  static inline bool FailReason_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      FailReason* value) {
    return CreateAccountResponse_FailReason_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kRequestIDFieldNumber = 1,
    kUserIDFieldNumber = 2,
    kSuccessFieldNumber = 4,
    kFailReasonFieldNumber = 3,
  };
  // required int32 requestID = 1;
  bool has_requestid() const;
  private:
  bool _internal_has_requestid() const;
  public:
  void clear_requestid();
  ::PROTOBUF_NAMESPACE_ID::int32 requestid() const;
  void set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_requestid() const;
  void _internal_set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional int32 userID = 2;
  bool has_userid() const;
  private:
  bool _internal_has_userid() const;
  public:
  void clear_userid();
  ::PROTOBUF_NAMESPACE_ID::int32 userid() const;
  void set_userid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_userid() const;
  void _internal_set_userid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required bool success = 4;
  bool has_success() const;
  private:
  bool _internal_has_success() const;
  public:
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // required .Database.CreateAccountResponse.FailReason failReason = 3;
  bool has_failreason() const;
  private:
  bool _internal_has_failreason() const;
  public:
  void clear_failreason();
  ::Database::CreateAccountResponse_FailReason failreason() const;
  void set_failreason(::Database::CreateAccountResponse_FailReason value);
  private:
  ::Database::CreateAccountResponse_FailReason _internal_failreason() const;
  void _internal_set_failreason(::Database::CreateAccountResponse_FailReason value);
  public:

  // @@protoc_insertion_point(class_scope:Database.CreateAccountResponse)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 requestid_;
  ::PROTOBUF_NAMESPACE_ID::int32 userid_;
  bool success_;
  int failreason_;
  friend struct ::TableStruct_CreateAccountResponse_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CreateAccountResponse

// required int32 requestID = 1;
inline bool CreateAccountResponse::_internal_has_requestid() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool CreateAccountResponse::has_requestid() const {
  return _internal_has_requestid();
}
inline void CreateAccountResponse::clear_requestid() {
  requestid_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 CreateAccountResponse::_internal_requestid() const {
  return requestid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 CreateAccountResponse::requestid() const {
  // @@protoc_insertion_point(field_get:Database.CreateAccountResponse.requestID)
  return _internal_requestid();
}
inline void CreateAccountResponse::_internal_set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  requestid_ = value;
}
inline void CreateAccountResponse::set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_requestid(value);
  // @@protoc_insertion_point(field_set:Database.CreateAccountResponse.requestID)
}

// optional int32 userID = 2;
inline bool CreateAccountResponse::_internal_has_userid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool CreateAccountResponse::has_userid() const {
  return _internal_has_userid();
}
inline void CreateAccountResponse::clear_userid() {
  userid_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 CreateAccountResponse::_internal_userid() const {
  return userid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 CreateAccountResponse::userid() const {
  // @@protoc_insertion_point(field_get:Database.CreateAccountResponse.userID)
  return _internal_userid();
}
inline void CreateAccountResponse::_internal_set_userid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  userid_ = value;
}
inline void CreateAccountResponse::set_userid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_userid(value);
  // @@protoc_insertion_point(field_set:Database.CreateAccountResponse.userID)
}

// required .Database.CreateAccountResponse.FailReason failReason = 3;
inline bool CreateAccountResponse::_internal_has_failreason() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool CreateAccountResponse::has_failreason() const {
  return _internal_has_failreason();
}
inline void CreateAccountResponse::clear_failreason() {
  failreason_ = 1;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::Database::CreateAccountResponse_FailReason CreateAccountResponse::_internal_failreason() const {
  return static_cast< ::Database::CreateAccountResponse_FailReason >(failreason_);
}
inline ::Database::CreateAccountResponse_FailReason CreateAccountResponse::failreason() const {
  // @@protoc_insertion_point(field_get:Database.CreateAccountResponse.failReason)
  return _internal_failreason();
}
inline void CreateAccountResponse::_internal_set_failreason(::Database::CreateAccountResponse_FailReason value) {
  assert(::Database::CreateAccountResponse_FailReason_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  failreason_ = value;
}
inline void CreateAccountResponse::set_failreason(::Database::CreateAccountResponse_FailReason value) {
  _internal_set_failreason(value);
  // @@protoc_insertion_point(field_set:Database.CreateAccountResponse.failReason)
}

// required bool success = 4;
inline bool CreateAccountResponse::_internal_has_success() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool CreateAccountResponse::has_success() const {
  return _internal_has_success();
}
inline void CreateAccountResponse::clear_success() {
  success_ = false;
  _has_bits_[0] &= ~0x00000004u;
}
inline bool CreateAccountResponse::_internal_success() const {
  return success_;
}
inline bool CreateAccountResponse::success() const {
  // @@protoc_insertion_point(field_get:Database.CreateAccountResponse.success)
  return _internal_success();
}
inline void CreateAccountResponse::_internal_set_success(bool value) {
  _has_bits_[0] |= 0x00000004u;
  success_ = value;
}
inline void CreateAccountResponse::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:Database.CreateAccountResponse.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Database

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Database::CreateAccountResponse_FailReason> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Database::CreateAccountResponse_FailReason>() {
  return ::Database::CreateAccountResponse_FailReason_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_CreateAccountResponse_2eproto
