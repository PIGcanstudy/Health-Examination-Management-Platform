<template>
  <div class="container">
    <!-- 人脸采集 -->
    <div class="shoting">
      <div class="pic" style="cursor: pointer; padding: 0 20px 20px 20px">
        <div class="pic-box">
          <img :src="previewImage || '/src/assets/medicalinfo/pic-icon.svg'" :style="previewImage ? previewImageStyle : defaultImageStyle" />
          <span v-if="!previewImage" style="height: auto; line-height: 0; margin-top: 30px; color: rgb(41, 136, 243)">人脸采集</span>
        </div>
        <el-upload :before-upload="handleBeforeUpload" list-type="picture-card" style="display: block; width: 100%; height: 100%; position: absolute; top: 0; left: 0; opacity: 0"> > </el-upload>
      </div>
      <!-- temp(当封装好弹窗组件后，调用弹窗组件实现上传头像) -->
      <!-- <el-upload :before-upload="handleBeforeUpload" list-type="picture-card">
        <el-button type="primary">选择图片</el-button>
      </el-upload>
      <div v-if="previewImage">
        <img :src="previewImage" alt="Preview" style="max-width: 100%" />
      </div> -->
    </div>
    <!-- 右侧卡片 -->
    <div class="right-card">
      <!-- 完成进度(登记、在检、总检、已完成) -->
      <div class="step">
        <ul>
          <li v-for="(item, index) in progressSteps" :key="index">
            <img :src="getImagePath(index)" />
            <span>{{ item }}</span>
          </li>
        </ul>
      </div>
      <!-- 个人信息 -->
      <el-form ref="form" label-width="80px" :model="personInfo" :rules="rules" class="flex-form">
        <el-form-item label="体检编号" prop="physical_id">
          <el-input v-model.trim="$props.personInfo.physical_id" autocomplete="off" disabled />
        </el-form-item>
        <el-form-item label="身份证号" prop="id_card">
          <el-input v-model.trim="$props.personInfo.id_card" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="姓名" prop="person_name">
          <el-input v-model.trim="$props.personInfo.person_name" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="性别" prop="sex">
          <el-input v-model.trim="$props.personInfo.sex" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="年龄" prop="age">
          <el-input v-model.trim="$props.personInfo.age" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="体检类型" prop="physical_type">
          <el-input v-model.trim="$props.personInfo.physical_type" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="联系电话" prop="mobile">
          <el-input v-model.trim="$props.personInfo.mobile" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="单位名称" prop="unit_name">
          <el-input v-model.trim="$props.personInfo.unit_name" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="婚姻状态" prop="marry_type">
          <el-select v-model.trim="$props.personInfo.marry_type" placeholder="请选择">
            <el-option label="未婚" value="未婚" />
            <el-option label="已婚" value="已婚" />
            <el-option label="离异" value="离异" />
          </el-select>
        </el-form-item>
        <el-form-item label="分组名称" prop="type_name">
          <el-select v-model.trim="$props.personInfo.type_name" placeholder="请选择">
            <el-option label="男" value="男" />
            <el-option label="女" value="女" />
          </el-select>
        </el-form-item>
      </el-form>
    </div>
  </div>
</template>
<script setup>
import { ref, computed } from 'vue'
// 向子组件传递的数据
const props = defineProps({
  // 当前流程
  currentProgress: {
    type: Number,
    required: true
  },
  // 共有哪些流程
  progressSteps: {
    type: Array,
    required: true
  },
  // 个人信息
  personInfo: {
    type: Object,
    required: true
  }
})
// 定义个人信息中必需的信息
const rules = ref({
  id_card: [{ required: true }],
  person_name: [{ required: true }],
  sex: [{ required: true }],
  age: [{ required: true }],
  physical_type: [{ required: true }]
})
// 根据当前流程判断展示的图片
function getImagePath(index) {
  if (index === 0) return props.currentProgress > 0 ? '/src/assets/medicalinfo/start_check.png' : '/src/assets/medicalinfo/start_nomal.png'
  if (index === props.progressSteps.length - 1) return props.currentProgress === props.progressSteps.length ? '/src/assets/medicalinfo/end_check.png' : '/src/assets/medicalinfo/end_nomal.png'
  return props.currentProgress > 1 && index < props.currentProgress ? '/src/assets/medicalinfo/mid_check.png' : '/src/assets/medicalinfo/mid_nomal.png'
}
/* 上传图片处理 */
const previewImage = ref('')

const handleBeforeUpload = (file) => {
  const reader = new FileReader()
  reader.onload = (e) => {
    previewImage.value = e.target.result
  }
  reader.readAsDataURL(file)
  // 返回false阻止文件自动上传
  return false
}
// 默认图片样式
const defaultImageStyle = computed(() => ({
  display: 'block',
  margin: '0 auto',
  paddingTop: '40px'
}))
// 当上传图片时展示该样式
const previewImageStyle = computed(() => ({
  display: 'block',
  width: '100%',
  height: '100%',
  objectFit: 'cover' // 确保图片不失真
}))
</script>
<!-- 局内样式 -->
<style scoped>
/* 控制整体布局 */
.container {
  display: flex;
  justify-content: space-between;
}
.shoting .right-card {
  flex: 1; /* 调整 flex 基础大小，或使用具体的宽度，例如 flex: 0 0 300px; */
}
.shoting {
  flex: 1 1 12%; /* 让.shoting占据更多的空间 */
}
.right-card {
  flex: 1 1 90%; /* 让.right-card占据更多的空间 */
}
/* 人脸采集 */
.pic-box {
  border: 1px dashed #2988f3;
  width: 130px;
  height: 150px;
  text-align: center;
}
/* 当前流程(登记、在检查...) */
.step {
  ul {
    list-style: none;
    display: flex;
    padding: 0;
    margin: 0;

    li {
      position: relative;
      width: 100px;
      height: 30px;
      margin-right: -10px;

      span {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        z-index: 10;
        white-space: nowrap;
        color: #fff;
        font-size: 13px;
        font-weight: 600;
      }
    }
  }
}
/* 个人信息表单 */
.flex-form {
  padding-top: 20px;
  display: flex;
  flex-wrap: wrap; /* 允许表单项换行 */
  align-items: flex-start; /* 对齐表单项 */
}

.flex-form .el-form-item {
  flex: 1 1 200px; /* 每个表单项的基础大小和增长因子 */
}
</style>
<!-- 全局样式 -->
<style>
.el-input {
  width: 180px;
}
</style>
